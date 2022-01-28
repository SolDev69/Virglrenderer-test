/*
 * Copyright 2021 Google LLC
 * SPDX-License-Identifier: MIT
 */

#include "vkr_common.h"

#include <stdarg.h>
#include <stdio.h>

#include "venus-protocol/vn_protocol_renderer_info.h"

#include "vkr_context.h"
#include "vkr_cs.h"

static const struct vn_info_extension_table vkr_extension_table = {
   /* Venus extensions */
   .EXT_command_serialization = true,
   .MESA_venus_protocol = true,
   /* promoted to VK_VERSION_1_1 */
   .KHR_16bit_storage = true,
   .KHR_bind_memory2 = true,
   .KHR_dedicated_allocation = true,
   .KHR_descriptor_update_template = true,
   .KHR_device_group = true,
   .KHR_device_group_creation = true,
   .KHR_external_fence = true,
   .KHR_external_fence_capabilities = true,
   .KHR_external_memory = true,
   .KHR_external_memory_capabilities = true,
   .KHR_external_semaphore = true,
   .KHR_external_semaphore_capabilities = true,
   .KHR_get_memory_requirements2 = true,
   .KHR_get_physical_device_properties2 = true,
   .KHR_maintenance1 = true,
   .KHR_maintenance2 = true,
   .KHR_maintenance3 = true,
   .KHR_multiview = true,
   .KHR_relaxed_block_layout = true,
   .KHR_sampler_ycbcr_conversion = true,
   .KHR_shader_draw_parameters = true,
   .KHR_storage_buffer_storage_class = true,
   .KHR_variable_pointers = true,
   /* promoted to VK_VERSION_1_2 */
   .KHR_8bit_storage = true,
   .KHR_buffer_device_address = true,
   .KHR_create_renderpass2 = true,
   .KHR_depth_stencil_resolve = true,
   .KHR_draw_indirect_count = true,
   .KHR_driver_properties = true,
   .KHR_image_format_list = true,
   .KHR_imageless_framebuffer = true,
   .KHR_sampler_mirror_clamp_to_edge = true,
   .KHR_separate_depth_stencil_layouts = true,
   .KHR_shader_atomic_int64 = true,
   .KHR_shader_float16_int8 = true,
   .KHR_shader_float_controls = true,
   .KHR_shader_subgroup_extended_types = true,
   .KHR_spirv_1_4 = true,
   .KHR_timeline_semaphore = true,
   .KHR_uniform_buffer_standard_layout = true,
   .KHR_vulkan_memory_model = true,
   .EXT_descriptor_indexing = true,
   .EXT_host_query_reset = true,
   .EXT_sampler_filter_minmax = true,
   .EXT_scalar_block_layout = true,
   .EXT_separate_stencil_usage = true,
   .EXT_shader_viewport_index_layer = true,
   /* KHR extensions */
   .KHR_external_memory_fd = true,
   /* EXT extensions */
   .EXT_external_memory_dma_buf = true,
   .EXT_image_drm_format_modifier = true,
   .EXT_queue_family_foreign = true,
   .EXT_transform_feedback = true,
};

void
vkr_log(const char *fmt, ...)
{
   const char prefix[] = "vkr: ";
   char line[1024];
   size_t len;
   va_list va;
   int ret;

   len = ARRAY_SIZE(prefix) - 1;
   memcpy(line, prefix, len);

   va_start(va, fmt);
   ret = vsnprintf(line + len, ARRAY_SIZE(line) - len, fmt, va);
   va_end(va);

   if (ret < 0) {
      const char log_error[] = "log error";
      memcpy(line + len, log_error, ARRAY_SIZE(log_error) - 1);
      len += ARRAY_SIZE(log_error) - 1;
   } else if ((size_t)ret < ARRAY_SIZE(line) - len) {
      len += ret;
   } else {
      len = ARRAY_SIZE(line) - 1;
   }

   /* make room for newline */
   if (len + 1 >= ARRAY_SIZE(line))
      len--;

   line[len++] = '\n';
   line[len] = '\0';

   virgl_log(line);
}

uint32_t
vkr_extension_get_spec_version(const char *name)
{
   const struct vn_info_extension *ext = vn_info_extension_get(name);
   return ext && vkr_extension_table.enabled[ext->index] ? ext->spec_version : 0;
}

void
object_array_fini(struct object_array *arr)
{
   if (!arr->objects_stolen) {
      for (uint32_t i = 0; i < arr->count; i++)
         free(arr->objects[i]);
   }

   free(arr->objects);
   free(arr->handle_storage);
}

bool
object_array_init(struct vkr_context *ctx,
                  struct object_array *arr,
                  uint32_t count,
                  VkObjectType obj_type,
                  size_t obj_size,
                  size_t handle_size,
                  const void *obj_id_handles)
{
   arr->count = count;

   arr->objects = malloc(sizeof(*arr->objects) * count);
   if (!arr->objects)
      return false;

   arr->handle_storage = malloc(handle_size * count);
   if (!arr->handle_storage) {
      free(arr->objects);
      return false;
   }

   arr->objects_stolen = false;
   for (uint32_t i = 0; i < count; i++) {
      const void *obj_id_handle = (const char *)obj_id_handles + handle_size * i;
      struct vkr_object *obj =
         vkr_context_alloc_object(ctx, obj_size, obj_type, obj_id_handle);
      if (!obj) {
         arr->count = i;
         object_array_fini(arr);
         return false;
      }

      arr->objects[i] = obj;
   }

   return arr;
}

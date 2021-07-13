/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_SHADER_MODULE_H
#define VN_PROTOCOL_RENDERER_SHADER_MODULE_H

#include "vn_protocol_renderer_structs.h"

/* struct VkShaderModuleCreateInfo chain */

static inline void *
vn_decode_VkShaderModuleCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkShaderModuleCreateInfo_self_temp(struct vn_cs_decoder *dec, VkShaderModuleCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_size_t(dec, &val->codeSize);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->codeSize / 4);
        val->pCode = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pCode) * array_size);
        if (!val->pCode) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pCode, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pCode = NULL;
    }
}

static inline void
vn_decode_VkShaderModuleCreateInfo_temp(struct vn_cs_decoder *dec, VkShaderModuleCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkShaderModuleCreateInfo_pnext_temp(dec);
    vn_decode_VkShaderModuleCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkShaderModuleCreateInfo_handle_self(VkShaderModuleCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->codeSize */
    /* skip val->pCode */
}

static inline void
vn_replace_VkShaderModuleCreateInfo_handle(VkShaderModuleCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            vn_replace_VkShaderModuleCreateInfo_handle_self((VkShaderModuleCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

static inline void vn_decode_vkCreateShaderModule_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateShaderModule *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkShaderModuleCreateInfo_temp(dec, (VkShaderModuleCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pShaderModule = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pShaderModule));
        if (!args->pShaderModule) return;
        vn_decode_VkShaderModule(dec, args->pShaderModule);
    } else {
        args->pShaderModule = NULL;
    }
}

static inline void vn_replace_vkCreateShaderModule_args_handle(struct vn_command_vkCreateShaderModule *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkShaderModuleCreateInfo_handle((VkShaderModuleCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pShaderModule */
}

static inline void vn_encode_vkCreateShaderModule_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateShaderModule *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateShaderModule_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pShaderModule))
        vn_encode_VkShaderModule(enc, args->pShaderModule);
}

static inline void vn_decode_vkDestroyShaderModule_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyShaderModule *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkShaderModule_lookup(dec, &args->shaderModule);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyShaderModule_args_handle(struct vn_command_vkDestroyShaderModule *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkShaderModule_handle(&args->shaderModule);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyShaderModule_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyShaderModule *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyShaderModule_EXT});

    /* skip args->device */
    /* skip args->shaderModule */
    /* skip args->pAllocator */
}

static inline void vn_dispatch_vkCreateShaderModule(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateShaderModule args;

    if (!ctx->dispatch_vkCreateShaderModule) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateShaderModule_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateShaderModule(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateShaderModule returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateShaderModule_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyShaderModule(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyShaderModule args;

    if (!ctx->dispatch_vkDestroyShaderModule) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyShaderModule_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyShaderModule(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyShaderModule_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#endif /* VN_PROTOCOL_RENDERER_SHADER_MODULE_H */

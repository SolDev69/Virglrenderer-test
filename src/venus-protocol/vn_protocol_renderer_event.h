/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_EVENT_H
#define VN_PROTOCOL_RENDERER_EVENT_H

#include "vn_protocol_renderer_structs.h"

/* struct VkEventCreateInfo chain */

static inline void *
vn_decode_VkEventCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkEventCreateInfo_self_temp(struct vn_cs_decoder *dec, VkEventCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
}

static inline void
vn_decode_VkEventCreateInfo_temp(struct vn_cs_decoder *dec, VkEventCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EVENT_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkEventCreateInfo_pnext_temp(dec);
    vn_decode_VkEventCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkEventCreateInfo_handle_self(VkEventCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
}

static inline void
vn_replace_VkEventCreateInfo_handle(VkEventCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            vn_replace_VkEventCreateInfo_handle_self((VkEventCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

static inline void vn_decode_vkCreateEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateEvent *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkEventCreateInfo_temp(dec, (VkEventCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pEvent = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pEvent));
        if (!args->pEvent) return;
        vn_decode_VkEvent(dec, args->pEvent);
    } else {
        args->pEvent = NULL;
    }
}

static inline void vn_replace_vkCreateEvent_args_handle(struct vn_command_vkCreateEvent *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkEventCreateInfo_handle((VkEventCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pEvent */
}

static inline void vn_encode_vkCreateEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateEvent_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pEvent))
        vn_encode_VkEvent(enc, args->pEvent);
}

static inline void vn_decode_vkDestroyEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyEvent *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkEvent_lookup(dec, &args->event);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyEvent_args_handle(struct vn_command_vkDestroyEvent *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkEvent_handle(&args->event);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyEvent_EXT});

    /* skip args->device */
    /* skip args->event */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetEventStatus_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetEventStatus *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkEvent_lookup(dec, &args->event);
}

static inline void vn_replace_vkGetEventStatus_args_handle(struct vn_command_vkGetEventStatus *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkEvent_handle(&args->event);
}

static inline void vn_encode_vkGetEventStatus_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetEventStatus *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetEventStatus_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->event */
}

static inline void vn_decode_vkSetEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkSetEvent *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkEvent_lookup(dec, &args->event);
}

static inline void vn_replace_vkSetEvent_args_handle(struct vn_command_vkSetEvent *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkEvent_handle(&args->event);
}

static inline void vn_encode_vkSetEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkSetEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkSetEvent_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->event */
}

static inline void vn_decode_vkResetEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkResetEvent *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkEvent_lookup(dec, &args->event);
}

static inline void vn_replace_vkResetEvent_args_handle(struct vn_command_vkResetEvent *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkEvent_handle(&args->event);
}

static inline void vn_encode_vkResetEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkResetEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkResetEvent_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->event */
}

static inline void vn_dispatch_vkCreateEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateEvent args;

    if (!ctx->dispatch_vkCreateEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateEvent_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateEvent(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateEvent returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyEvent args;

    if (!ctx->dispatch_vkDestroyEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyEvent_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyEvent(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetEventStatus(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetEventStatus args;

    if (!ctx->dispatch_vkGetEventStatus) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetEventStatus_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetEventStatus(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkGetEventStatus returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetEventStatus_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkSetEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkSetEvent args;

    if (!ctx->dispatch_vkSetEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkSetEvent_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkSetEvent(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkSetEvent returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkSetEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkResetEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkResetEvent args;

    if (!ctx->dispatch_vkResetEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkResetEvent_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkResetEvent(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkResetEvent returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkResetEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#endif /* VN_PROTOCOL_RENDERER_EVENT_H */

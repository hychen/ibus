/* -*- mode: C; c-basic-offset: 4; indent-tabs-mode: nil; -*- */
/* vim:set et sts=4: */
/* IBus - The Input Bus
 * Copyright (C) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 * Copyright (C) 2008-2010 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
/**
 * SECTION: ibusattribute
 * @short_description: Attributes of IBusText.
 * @see_also: #IBusText
 * @stability: Stable
 *
 * An IBusAttribute represents an attribute that associate to IBusText.
 * It decorates preedit buffer and auxiliary text with underline, foreground and background colors.
 */
#ifndef __IBUS_ATTRIBUTE_H_
#define __IBUS_ATTRIBUTE_H_

#include "ibusserializable.h"

G_BEGIN_DECLS

/*
 * Type macros.
 */
/* define IBusAttribute macros */
#define IBUS_TYPE_ATTRIBUTE             \
    (ibus_attribute_get_type ())
#define IBUS_ATTRIBUTE(obj)             \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), IBUS_TYPE_ATTRIBUTE, IBusAttribute))
#define IBUS_ATTRIBUTE_CLASS(klass)     \
    (G_TYPE_CHECK_CLASS_CAST ((klass), IBUS_TYPE_ATTRIBUTE, IBusAttributeClass))
#define IBUS_IS_ATTRIBUTE(obj)          \
    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IBUS_TYPE_ATTRIBUTE))
#define IBUS_IS_ATTRIBUTE_CLASS(klass)  \
    (G_TYPE_CHECK_CLASS_TYPE ((klass), IBUS_TYPE_ATTRIBUTE))
#define IBUS_ATTRIBUTE_GET_CLASS(obj)   \
    (G_TYPE_INSTANCE_GET_CLASS ((obj), IBUS_TYPE_ATTRIBUTE, IBusAttributeClass))

/**
 * IBusAttrType:
 * @IBUS_ATTR_TYPE_UNDERLINE: Decorate with underline.
 * @IBUS_ATTR_TYPE_FOREGROUND: Foreground color.
 * @IBUS_ATTR_TYPE_BACKGROUND: Background color.
 *
 * Type enumeration of IBusText attribute.
 */
typedef enum {
    IBUS_ATTR_TYPE_UNDERLINE    = 1,
    IBUS_ATTR_TYPE_FOREGROUND   = 2,
    IBUS_ATTR_TYPE_BACKGROUND   = 3,
} IBusAttrType;

/**
 * IBusAttrUnderline:
 * @IBUS_ATTR_UNDERLINE_NONE: No underline.
 * @IBUS_ATTR_UNDERLINE_SINGLE: Single underline.
 * @IBUS_ATTR_UNDERLINE_DOUBLE: Double underline.
 * @IBUS_ATTR_UNDERLINE_LOW: Low underline ? %FIXME
 * @IBUS_ATTR_UNDERLINE_ERROR: Error underline
 *
 * Type of IBusText attribute.
 */
typedef enum {
    IBUS_ATTR_UNDERLINE_NONE    = 0,
    IBUS_ATTR_UNDERLINE_SINGLE  = 1,
    IBUS_ATTR_UNDERLINE_DOUBLE  = 2,
    IBUS_ATTR_UNDERLINE_LOW     = 3,
    IBUS_ATTR_UNDERLINE_ERROR   = 4,
} IBusAttrUnderline;

typedef struct _IBusAttribute IBusAttribute;
typedef struct _IBusAttributeClass IBusAttributeClass;

/**
 * IBusAttribute:
 * @type: IBusAttributeType
 * @value: Value for the type.
 * @start_index: The starting index, inclusive.
 * @end_index: The ending index, exclusive.
 *
 * Signify the type, value and scope of the attribute.
 * The scope starts from @start_index till the @end_index-1.
 */
struct _IBusAttribute {
    IBusSerializable parent;

    /*< public >*/
    guint type;
    guint value;
    guint start_index;
    guint end_index;
};

struct _IBusAttributeClass {
    IBusSerializableClass parent;
};

/**
 * ibus_attribute_get_type:
 * @returns: GType of IBusAttribute.
 *
 * Returns GType of IBusAttribute.
 */
GType                ibus_attribute_get_type    ();

/**
 * ibus_attribute_new:
 * @type: Type of the attribute.
 * @value: Value of the attribute.
 * @start_index: Where attribute starts.
 * @end_index: Where attribute ends.
 * @returns: A newly allocated IBusAttribute.
 *
 * New an IBusAttribute.
 */
IBusAttribute       *ibus_attribute_new         (guint           type,
                                                 guint           value,
                                                 guint           start_index,
                                                 guint           end_index);
/**
 * ibus_attr_underline_new:
 * @underline_type: Type of underline.
 * @start_index: Where attribute starts.
 * @end_index: Where attribute ends.
 * @returns: A newly allocated IBusAttribute.
 *
 * New an underline IBusAttribute.
 */
IBusAttribute       *ibus_attr_underline_new    (guint           underline_type,
                                                 guint           start_index,
                                                 guint           end_index);
/**
 * ibus_attr_foreground_new:
 * @color: Color in RGB.
 * @start_index: Where attribute starts.
 * @end_index: Where attribute ends.
 * @returns: A newly allocated IBusAttribute.
 *
 * New an foreground IBusAttribute.
 */
IBusAttribute       *ibus_attr_foreground_new   (guint           color,
                                                 guint           start_index,
                                                 guint           end_index);
/**
 * ibus_attr_background_new:
 * @color: Color in RGB.
 * @start_index: Where attribute starts.
 * @end_index: Where attribute ends.
 * @returns: A newly allocated IBusAttribute.
 *
 * New an background IBusAttribute.
 */
IBusAttribute       *ibus_attr_background_new   (guint           color,
                                                 guint           start_index,
                                                 guint           end_index);

G_END_DECLS
#endif


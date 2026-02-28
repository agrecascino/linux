// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct td4100_5_5 {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
	struct gpio_desc *backlight_gpio;
};

static inline struct td4100_5_5 *to_td4100_5_5(struct drm_panel *panel)
{
	return container_of(panel, struct td4100_5_5, panel);
}

static void td4100_5_5_reset(struct td4100_5_5 *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
	
	gpiod_set_value_cansleep(ctx->backlight_gpio, 0);
	usleep_range(5000, 6000);
}

static int td4100_5_5_on(struct td4100_5_5 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb3, 0x10, 0x00, 0x06);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb6,
				     0x32, 0x43, 0x80, 0x00, 0x00, 0x07, 0x86);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xba,
				     0x07, 0x87, 0x3a, 0x0a, 0x2d, 0x88);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbb, 0x00, 0xb4, 0xa0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc, 0x00, 0xb4, 0xa0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbd, 0x00, 0xb4, 0xa0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbe, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc0,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc1,
				     0x04, 0x48, 0x01, 0x00, 0x33, 0x08, 0x11,
				     0x00, 0x11, 0x00, 0x73, 0x23, 0x23, 0x11,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0xdf, 0x00,
				     0x30, 0x00, 0x01, 0x00, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2,
				     0x00, 0xf0, 0x05, 0x00, 0x0a, 0x04, 0x08,
				     0x00, 0x24, 0x19, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x01, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3,
				     0x51, 0x15, 0x11, 0x51, 0x10, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
				     0x01, 0x03, 0x28, 0x00, 0x01, 0x01, 0x01,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67,
				     0x01, 0x00, 0x00, 0x00, 0x00, 0x67, 0x01,
				     0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc4,
				     0x70, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x01, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5,
				     0x08, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00,
				     0x00, 0x2d, 0x41);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6,
				     0xc2, 0x14, 0x89, 0x00, 0x00, 0x14, 0x89,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0xc2, 0xc2);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7,
				     0x00, 0x0a, 0x14, 0x21, 0x2d, 0x37, 0x4f,
				     0x61, 0x71, 0x7f, 0x33, 0x40, 0x4e, 0x64,
				     0x6e, 0x7d, 0x90, 0xa0, 0xb0, 0x00, 0x0a,
				     0x14, 0x21, 0x2d, 0x37, 0x4f, 0x61, 0x71,
				     0x7f, 0x33, 0x40, 0x4e, 0x64, 0x6e, 0x7d,
				     0x90, 0xa0, 0xb0, 0x00, 0x97, 0x00, 0x97,
				     0x00, 0x97, 0x00, 0x97);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc8,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0xfc, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc9,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0xfc, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xca,
				     0x1d, 0xfc, 0xdc, 0xee, 0x00, 0xe6, 0xdb,
				     0xd8, 0x00, 0xc9, 0xee, 0xf3, 0x00, 0x08,
				     0x06, 0x00, 0x00, 0x08, 0xf3, 0x05, 0x00,
				     0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcc,
				     0x00, 0x00, 0x00, 0x00, 0xd2, 0x72, 0x12,
				     0x16, 0x1a, 0x1e, 0xd0, 0x70, 0x42, 0x46,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x44, 0x40, 0x70, 0xd0, 0x1c,
				     0x18, 0x14, 0x10, 0x72, 0xd2, 0x00, 0x00,
				     0x00, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcd,
				     0x03, 0x06, 0x69, 0x01, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x01, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xce,
				     0x7d, 0x40, 0x48, 0x56, 0x67, 0x78, 0x88,
				     0x98, 0xa7, 0xb5, 0xc3, 0xd1, 0xde, 0xe9,
				     0xf2, 0xfa, 0xff, 0x04, 0x00, 0x01, 0x04,
				     0x45, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcf, 0x48, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd0,
				     0x11, 0x04, 0x59, 0xd9, 0x03, 0x10, 0x10,
				     0x40, 0x19, 0x08, 0x99, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd1, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd3,
				     0xbb, 0x3b, 0x33, 0x3b, 0x44, 0x3b, 0x44,
				     0x3b, 0x00, 0x00, 0xec, 0x9b, 0x8b, 0x23,
				     0x22, 0xb3, 0xb3, 0x3b, 0xbb, 0x4f, 0xd0,
				     0x3c, 0x10, 0x12, 0x10, 0x00, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd4,
				     0x80, 0x04, 0x04, 0x33, 0x00, 0x04, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x0a, 0x90, 0x05,
				     0x00, 0x64, 0x94);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd6, 0x41);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd7,
				     0xf6, 0xff, 0x03, 0x05, 0x43, 0x24, 0x80,
				     0x1f, 0xc7, 0x1f, 0x1b, 0x00, 0x0f, 0x01,
				     0x20, 0x08, 0x80, 0x3f, 0x00, 0x78, 0x00,
				     0x40, 0x24, 0x15, 0x00, 0x33, 0x02, 0xc0,
				     0xaf, 0xcb, 0x60, 0x30, 0xfc, 0x00, 0x3f,
				     0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd8,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdd, 0x30, 0x06, 0x23, 0x65);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x0c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_POWER_SAVE, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_CABC_MIN_BRIGHTNESS,
				     0x30);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);

	return dsi_ctx.accum_err;
}

static int td4100_5_5_off(struct td4100_5_5 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 80);

	return dsi_ctx.accum_err;
}

static int td4100_5_5_prepare(struct drm_panel *panel)
{
	struct td4100_5_5 *ctx = to_td4100_5_5(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	td4100_5_5_reset(ctx);

	ret = td4100_5_5_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	return 0;
}

static int td4100_5_5_unprepare(struct drm_panel *panel)
{
	struct td4100_5_5 *ctx = to_td4100_5_5(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = td4100_5_5_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	return 0;
}

static const struct drm_display_mode td4100_5_5_mode = {
	.clock = (720 + 252 + 4 + 158) * (1280 + 127 + 127 + 125) * 60 / 1000,
	.hdisplay = 720,
	.hsync_start = 720 + 252,
	.hsync_end = 720 + 252 + 4,
	.htotal = 720 + 252 + 4 + 158,
	.vdisplay = 1280,
	.vsync_start = 1280 + 127,
	.vsync_end = 1280 + 127 + 127,
	.vtotal = 1280 + 127 + 127 + 125,
	.width_mm = 69,
	.height_mm = 122,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int td4100_5_5_get_modes(struct drm_panel *panel,
				struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &td4100_5_5_mode);
}

static const struct drm_panel_funcs td4100_5_5_panel_funcs = {
	.prepare = td4100_5_5_prepare,
	.unprepare = td4100_5_5_unprepare,
	.get_modes = td4100_5_5_get_modes,
};

static int td4100_5_5_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int td4100_5_5_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness;
}

static const struct backlight_ops td4100_5_5_bl_ops = {
	.update_status = td4100_5_5_bl_update_status,
	.get_brightness = td4100_5_5_bl_get_brightness,
};

static struct backlight_device *
td4100_5_5_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 256,
		.max_brightness = 256,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &td4100_5_5_bl_ops, &props);
}

static int td4100_5_5_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct td4100_5_5 *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct td4100_5_5, panel,
				   &td4100_5_5_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);
		
	ctx->backlight_gpio = devm_gpiod_get_optional(dev, "backlight", GPIOD_ASIS);
	if (IS_ERR(ctx->backlight_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->backlight_gpio),
				     "failed to get backlight-gpios\n");

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS |
			  MIPI_DSI_MODE_VIDEO_NO_HFP;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = td4100_5_5_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void td4100_5_5_remove(struct mipi_dsi_device *dsi)
{
	struct td4100_5_5 *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id td4100_5_5_of_match[] = {
	{ .compatible = "mdss,td4100-5-5" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, td4100_5_5_of_match);

static struct mipi_dsi_driver td4100_5_5_driver = {
	.probe = td4100_5_5_probe,
	.remove = td4100_5_5_remove,
	.driver = {
		.name = "panel-td4100-5-5",
		.of_match_table = td4100_5_5_of_match,
	},
};
module_mipi_dsi_driver(td4100_5_5_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for ss_dsi_panel_TD4100_5_5_HD");
MODULE_LICENSE("GPL");

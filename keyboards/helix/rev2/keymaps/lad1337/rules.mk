# QMK Standard Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
#   See TOP/keyboards/helix/rules.mk for a list of options that can be set.
#   See TOP/docs/config_options.md for more information.
#
LTO_ENABLE = yes  # if firmware size over limit, try this option
SPLIT_KEYBOARD = yes

# Helix Spacific Build Options
# HELIX_ROWS = 5              # Helix Rows is 4 or 5
OLED_ENABLE = no            # OLED_ENABLE
OLED_DRIVER_ENABLE = yes
# LOCAL_GLCDFONT = no         # use each keymaps "helixfont.h" insted of "common/glcdfont.c"

LED_BACK_ENABLE = no        # LED backlight (Enable WS2812 RGB underlight.)
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

LED_ANIMATIONS = no        # LED animations
EXTRAKEY_ENABLE = yes       
TAP_DANCE_ENABLE = yes
# IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)


# convert Helix-specific options (that represent combinations of standard options)
#   into QMK standard options.
include $(strip $(KEYBOARD_LOCAL_FEATURES_MK))

# Kaleidoscope-LangPack-German

![status][st:experimental]

 [st:stable]: https://img.shields.io/badge/stable-✔-black.png?style=flat&colorA=44cc11&colorB=494e52
 [st:broken]: https://img.shields.io/badge/broken-X-black.png?style=flat&colorA=e05d44&colorB=494e52
 [st:experimental]: https://img.shields.io/badge/experimental----black.png?style=flat&colorA=dfb317&colorB=494e52

German language pack for the Kaleidoscope. This plugin introduces a number of
new key codes, which can be used to input Hungarian symbols on any operating
system that supports a `Compose` key. 

## Using the plugin

To use the plugin, one needs to include the header, and add the new keycodes to
the keymap.

## Plugin symbols

The plugin provides the `German` object, and the following new keycodes:

### `Key_AUmlaut` (`DE_A_UMLAUT`)
The keycode results in ä, or Ä when shifted.

### `Key_OUmlaut DE_Key` (`DE_O_UMLAUT`)
The keycode results in ö, or Ö when shifted.

### `Key_UUmlaut DE_Key` (`DE_U_UMLAUT`)
The keycode results in ü, or Ü when shifted.

### `Key_Eszett DE_Key` (`DE_ESZETT`)
The keycode results in ß.
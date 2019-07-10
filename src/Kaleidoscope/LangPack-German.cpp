/* -*- mode: c++ -*-
 * Kaleidoscope-LangPack-German -- German language support.
 *
 * Copyright (c) 2018 Jochen Pfeiffer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
.* in the Software without restriction, including without limitation the rights
.* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
.* copies of the Software, and to permit persons to whom the Software is
.* furnished to do so, subject to the following conditions:
.*
.* The above copyright notice and this permission notice shall be included in all
.* copies or substantial portions of the Software.
.*
.* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
.* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
.* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
.* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
.* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
.* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
.* SOFTWARE.
 */


#include <Kaleidoscope-LangPack-German.h>
#include <Kaleidoscope-OneShot.h>

namespace kaleidoscope {
namespace language {
namespace {

static bool modifierActive(Key modifierKey);
static void pressKey(Key key);
static void releaseKey(Key key);
static void tapKey(Key key);
static void modifyForUmlaut();
static void modifyForEszett();

} // namespace
} // namespace language
} // namespace kaleidoscope


namespace kaleidoscope {
namespace language {

EventHandlerResult German::onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr, uint8_t keyState) {
  if (mapped_key.raw < DE_FIRST || mapped_key.raw > DE_LAST) {
    return EventHandlerResult::OK;
  }

  if (!keyToggledOn(keyState)) {
    return EventHandlerResult::EVENT_CONSUMED;
  }

  Key deKey;
  deKey.flags = KEY_FLAGS;

  switch (mapped_key.raw) {
  case DE_AUMLAUT:
    modifyForUmlaut();
    deKey.keyCode = Key_A.keyCode;
    break;
  case DE_OUMLAUT:
    modifyForUmlaut();
    deKey.keyCode = Key_O.keyCode;
    break;
  case DE_UUMLAUT:
    modifyForUmlaut();
    deKey.keyCode = Key_U.keyCode;
    break;
  case DE_ESZETT:
    modifyForEszett();
    deKey.keyCode = Key_S.keyCode;
    deKey.flags |= LALT_HELD;
    break;
  }

  mapped_key = deKey;
  return EventHandlerResult::OK;
}


namespace {

bool modifierActive(Key modifierKey) {
  return hid::wasModifierKeyActive(modifierKey) ||
         ::OneShot.isModifierActive(modifierKey);
}

void pressKey(Key key) {
  hid::pressKey(key);
  hid::sendKeyboardReport();
}

void releaseKey(Key key) {
  hid::releaseKey(key);
  hid::sendKeyboardReport();
}

void tapKey(Key key) {
  pressKey(key);
  releaseKey(key);
}

void modifyForUmlaut() {
  bool left_shift_active = modifierActive(Key_LeftShift);
  bool right_shift_active = modifierActive(Key_RightShift);

  if (left_shift_active) {
    releaseKey(Key_LeftShift);
  }

  if (right_shift_active) {
    releaseKey(Key_RightShift);
  }

  pressKey(Key_LeftAlt);
  tapKey(Key_U);
  releaseKey(Key_LeftAlt);

  if (left_shift_active) {
    pressKey(Key_LeftShift);
  }
  if (right_shift_active) {
    pressKey(Key_RightShift);
  }
}

void modifyForEszett() {
  bool left_shift_active = modifierActive(Key_LeftShift);
  bool right_shift_active = modifierActive(Key_RightShift);

  if (left_shift_active) {
    releaseKey(Key_LeftShift);
  }

  if (right_shift_active) {
    releaseKey(Key_RightShift);
  }
}

} // namespace
} // namespace language
} // namespacce kaleidoscope


kaleidoscope::language::German German;

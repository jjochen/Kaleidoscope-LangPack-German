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

static void pressKey(Key key);
static void releaseKey(Key key);
static void tapKey(Key key);
static void typeUmlaut(Key key);
static void typeEszett();

} // namespace
} // namespace language
} // namespace kaleidoscope


namespace kaleidoscope {
namespace language {

EventHandlerResult German::onKeyswitchEvent(Key &mapped_key, byte row, byte col, uint8_t keyState) {
  if (mapped_key.raw < DE_FIRST || mapped_key.raw > DE_LAST) {
    return EventHandlerResult::OK;
  }

  if (!keyToggledOn(keyState)) {
    return EventHandlerResult::EVENT_CONSUMED;
  }

  switch (mapped_key.raw) {
  case DE_A_UMLAUT:
    typeUmlaut(Key_A);
    break;
  case DE_O_UMLAUT:
    typeUmlaut(Key_A);
    break;
  case DE_U_UMLAUT:
    typeUmlaut(Key_A);
    break;
  case DE_ESZETT:
    typeUmlaut(Key_A);
    break;
  }

  return EventHandlerResult::OK;
}


namespace {

void pressKey(Key key) {
  kaleidoscope::hid::pressKey(key);
  kaleidoscope::hid::sendKeyboardReport();
}

void releaseKey(Key key) {
  kaleidoscope::hid::releaseKey(key);
  kaleidoscope::hid::sendKeyboardReport();
}

void tapKey(Key key) {
  pressKey(key);
  releaseKey(key);
}

void typeUmlaut(Key key) {
  tapKey(Key_RightAlt); // ???

  bool left_shift_active = kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift);
  if (left_shift_active) {
    releaseKey(Key_LeftShift);
  }

  bool right_shift_active = kaleidoscope::hid::wasModifierKeyActive(Key_RightShift);
  if (right_shift_active) {
    releaseKey(Key_RightShift);
  }

  pressKey(Key_RightAlt);
  tapKey(Key_U);
  releaseKey(Key_RightAlt);

  if (left_shift_active) {
    pressKey(Key_LeftShift);
  }
  if (right_shift_active) {
    pressKey(Key_RightShift);
  }

  tapKey(key);
}

void typeEszett() {
  tapKey(Key_RightAlt); // ???

  bool left_shift_active = kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift);
  if (left_shift_active) {
    releaseKey(Key_LeftShift);
  }

  bool right_shift_active = kaleidoscope::hid::wasModifierKeyActive(Key_RightShift);
  if (right_shift_active) {
    releaseKey(Key_RightShift);
  }

  // macOS
  pressKey(Key_RightAlt);
  tapKey(Key_S);
  releaseKey(Key_RightAlt);

  // ToDo handle other operating systems

  if (left_shift_active) {
    pressKey(Key_LeftShift);
  }
  if (right_shift_active) {
    pressKey(Key_RightShift);
  }
}

} // namespace
} // namespace language
} // namespacce kaleidoscope


kaleidoscope::language::German German;

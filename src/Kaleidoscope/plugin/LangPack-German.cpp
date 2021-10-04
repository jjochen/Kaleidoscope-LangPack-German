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
#include <Kaleidoscope-Macros.h>

namespace kaleidoscope {
namespace language {
namespace {

static bool isGermanLanguageKey(Key key);
static void modifyForUmlaut();

} // namespace
} // namespace language
} // namespace kaleidoscope


namespace kaleidoscope {
namespace language {

EventHandlerResult German::onKeyEvent(KeyEvent &event) {
  if (!isGermanLanguageKey(event.key)) {
    return EventHandlerResult::OK;
  }

  if (!keyToggledOn(event.state)) {
    return EventHandlerResult::EVENT_CONSUMED;
  }

  switch (event.key.getRaw()) {
  case DE_AUMLAUT:
    modifyForUmlaut();
    event.key = Key_A;
    break;
  case DE_OUMLAUT:
    modifyForUmlaut();
    event.key = Key_O;
    break;
  case DE_UUMLAUT:
    modifyForUmlaut();
    event.key = Key_U;
    break;
  case DE_ESZETT:
    event.key = LALT(Key_S);
    break;
  }

  return EventHandlerResult::OK;
}

namespace {

bool isGermanLanguageKey(Key key) {
  return (key.getRaw() >= ranges::DE_FIRST &&
          key.getRaw() <= ranges::DE_LAST);
}


void modifyForUmlaut() {
  KeyEvent shift_events[KeyAddr::upper_limit];
  int shift_index = 0;
  for (KeyAddr key_addr : KeyAddr::all()) {
    Key key = live_keys[key_addr];
    if (key == Key_LeftShift || key == Key_RightShift) {
      Runtime.handleKeyEvent(KeyEvent(key_addr, WAS_PRESSED | INJECTED, key));
      shift_events[shift_index] = KeyEvent(key_addr, IS_PRESSED | INJECTED, key);
      shift_index++;
    }
  }
  
  Runtime.handleKeyEvent(KeyEvent(KeyAddr::none(), IS_PRESSED | INJECTED, LALT(Key_U)));
  Runtime.handleKeyEvent(KeyEvent(KeyAddr::none(), WAS_PRESSED | INJECTED, LALT(Key_U)));
  
  for (int unshift_index = 0; unshift_index < shift_index; unshift_index++) {
    KeyEvent event = shift_events[unshift_index];
    Runtime.handleKeyEvent(event);
  }
}

} // namespace
} // namespace language
} // namespacce kaleidoscope


kaleidoscope::language::German German;

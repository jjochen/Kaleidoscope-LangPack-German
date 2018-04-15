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

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-Ranges.h>


#define DE_Key(n) (Key){ .raw = kaleidoscope::language::n}
#define Key_AUmlaut DE_Key(DE_A_UMLAUT) // Ä/ä
#define Key_OUmlaut DE_Key(DE_O_UMLAUT) // Ö/ö
#define Key_UUmlaut DE_Key(DE_U_UMLAUT) // Ü/ü
#define Key_Eszett DE_Key(DE_ESZETT) // ß


namespace kaleidoscope {
namespace language {

enum {
  DE_FIRST = kaleidoscope::ranges::DE_FIRST,
  DE_A_UMLAUT = DE_FIRST,
  DE_O_UMLAUT,
  DE_U_UMLAUT,
  DE_ESZETT,
  DE_LAST = DE_ESZETT
};


class German : public KaleidoscopePlugin {
 public:
  German(void);

  void begin(void) final;

  static void typeUmlaut(Key key);
  static void typeEszett();

 private:
  static Key eventHandlerHook(Key mapped_key, byte row, byte col, uint8_t key_state);

  static void pressKey(Key key);
  static void releaseKey(Key key);
  static void tapKey(Key key);
};

}
}

extern kaleidoscope::language::German German;

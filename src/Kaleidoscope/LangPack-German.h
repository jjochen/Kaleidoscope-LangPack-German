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


#define DE_KEY(n) (Key){ .raw = kaleidoscope::language::DE_ ## n }
#define Key_AUmlaut DE_KEY(AUMLAUT) // Ä/ä
#define Key_OUmlaut DE_KEY(OUMLAUT) // Ö/ö
#define Key_UUmlaut DE_KEY(UUMLAUT) // Ü/ü
#define Key_Eszett DE_KEY(ESZETT) // ß

namespace kaleidoscope {
namespace language {

enum {
  DE_FIRST = kaleidoscope::ranges::DE_FIRST,
  DE_AUMLAUT = DE_FIRST,
  DE_OUMLAUT,
  DE_UUMLAUT,
  DE_ESZETT,
  DE_LAST = DE_ESZETT
};


class German : public kaleidoscope::Plugin {
 public:
  German(void) {};
  EventHandlerResult onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr, uint8_t keyState);
};

}
}

extern kaleidoscope::language::German German;

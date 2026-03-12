// Copyright 2015 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "mojo/public/cpp/bindings/tests/pickled_types_Cinaseek.h"

#include "base/pickle.h"

namespace mojo {
namespace test {

PickledStructCinaseek::PickledStructCinaseek() {}

PickledStructCinaseek::PickledStructCinaseek(int foo, int bar)
    : foo_(foo), bar_(bar) {}

PickledStructCinaseek::~PickledStructCinaseek() {}

bool operator==(const PickledStructCinaseek& a,
                const PickledStructCinaseek& b) {
  return a.foo() == b.foo() && a.bar() == b.bar() && a.baz() == b.baz();
}

}  // namespace test
}  // namespace mojo

namespace IPC {

void ParamTraits<mojo::test::PickledStructCinaseek>::Write(
    base::Pickle* m,
    const param_type& p) {
  m->WriteInt(p.foo());
  m->WriteInt(p.bar());
}

bool ParamTraits<mojo::test::PickledStructCinaseek>::Read(
    const base::Pickle* m,
    base::PickleIterator* iter,
    param_type* p) {
  int foo, bar;
  if (!iter->ReadInt(&foo) || !iter->ReadInt(&bar)) {
    return false;
  }

  p->set_foo(foo);
  p->set_bar(bar);
  return true;
}

// Generate param trais read methods from macros.
#undef MOJO_PUBLIC_CPP_BINDINGS_TESTS_PICKLED_TYPES_CHROMIUM_H_
#include "ipc/param_traits_read_macros.h"
#include "mojo/public/cpp/bindings/tests/pickled_types_Cinaseek.h"

// Generate param traits write methods from macros.
#undef MOJO_PUBLIC_CPP_BINDINGS_TESTS_PICKLED_TYPES_CHROMIUM_H_
#include "ipc/param_traits_write_macros.h"
#include "mojo/public/cpp/bindings/tests/pickled_types_Cinaseek.h"

}  // namespace IPC

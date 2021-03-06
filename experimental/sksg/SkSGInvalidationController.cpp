/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkSGInvalidationController.h"

#include "SkRect.h"
#include "SkTLazy.h"

namespace sksg {

InvalidationController::InvalidationController() {}

void InvalidationController::inval(const SkRect& r, const SkMatrix& ctm) {
    SkTCopyOnFirstWrite<SkRect> rect(r);

    if (!ctm.isIdentity() && !ctm.mapRect(rect.writable())) {
        *rect.writable() = SkRect::MakeLTRB(SK_ScalarMin, SK_ScalarMin, SK_ScalarMax, SK_ScalarMax);
    }

    fRects.push(*rect);
}

} // namespace sksg

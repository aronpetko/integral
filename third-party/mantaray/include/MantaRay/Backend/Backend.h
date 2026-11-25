//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_BACKEND_H
#define MANTARAY_BACKEND_BACKEND_H

#include "ISA/AVX2.h"
#include "ISA/AVX512.h"
#include "ISA/AVX512VNNI.h"
#include "ISA/ISAOf.h"
#include "ISA/NEON.h"
#include "ISA/Scalar.h"
#include "ISA/SSE2.h"
#include "ISA/SSE41.h"
#include "Kernel/AccumulatorDot.h"
#include "Kernel/AccumulatorTransform.h"
#include "Kernel/Dense.h"
#include "Kernel/Geometry.h"
#include "Kernel/Nnz.h"
#include "Kernel/Pointwise.h"
#include "Kernel/Refresh.h"
#include "Kernel/RowIndex.h"
#include "Kernel/Sparse.h"
#include "Kernel/Update.h"

#endif //MANTARAY_BACKEND_BACKEND_H

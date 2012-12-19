/* Copyright (c) 2012 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef LIBRARIES_NACL_MOUNTS_REAL_PEPPER_INTERFACE_H_
#define LIBRARIES_NACL_MOUNTS_REAL_PEPPER_INTERFACE_H_

#include <ppapi/c/ppb.h>
#include <ppapi/c/ppb_core.h>
#include <ppapi/c/ppb_message_loop.h>
#include "pepper_interface.h"

// Forward declare interface classes.
#include "nacl_mounts/pepper/define_empty_macros.h"
#undef BEGIN_INTERFACE
#define BEGIN_INTERFACE(BaseClass, PPInterface, InterfaceString) \
    class Real##BaseClass;
#include "nacl_mounts/pepper/all_interfaces.h"
#include "nacl_mounts/pepper/undef_macros.h"

class RealPepperInterface : public PepperInterface {
 public:
  RealPepperInterface(PP_Instance instance,
                      PPB_GetInterface get_browser_interface);

  virtual PP_Instance GetInstance();
  virtual void AddRefResource(PP_Resource);
  virtual void ReleaseResource(PP_Resource);

// Interface getters.
#include "nacl_mounts/pepper/define_empty_macros.h"
#undef BEGIN_INTERFACE
#define BEGIN_INTERFACE(BaseClass, PPInterface, InterfaceString) \
    virtual BaseClass* Get##BaseClass();
#include "nacl_mounts/pepper/all_interfaces.h"
#include "nacl_mounts/pepper/undef_macros.h"

  int32_t InitializeMessageLoop();

 private:
  PP_Instance instance_;
  const PPB_Core* core_interface_;
  const PPB_MessageLoop* message_loop_interface_;

// Interface pointers.
#include "nacl_mounts/pepper/define_empty_macros.h"
#undef BEGIN_INTERFACE
#define BEGIN_INTERFACE(BaseClass, PPInterface, InterfaceString) \
    Real##BaseClass* BaseClass##interface_;
#include "nacl_mounts/pepper/all_interfaces.h"
#include "nacl_mounts/pepper/undef_macros.h"
};

#endif  // LIBRARIES_NACL_MOUNTS_REAL_PEPPER_INTERFACE_H_

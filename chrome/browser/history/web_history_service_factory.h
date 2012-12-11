// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_HISTORY_WEB_HISTORY_SERVICE_FACTORY_H_
#define CHROME_BROWSER_HISTORY_WEB_HISTORY_SERVICE_FACTORY_H_

#include "base/memory/singleton.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/profiles/profile_keyed_service_factory.h"

namespace history {
class WebHistoryService;
}

// Used for creating and fetching a per-profile instance of the
// WebHistoryService.
class WebHistoryServiceFactory : public ProfileKeyedServiceFactory {
 public:
  // Get the singleton instance of the factory.
  static WebHistoryServiceFactory* GetInstance();

  // Get the WebHistoryService for |profile|, creating one if needed.
  static history::WebHistoryService* GetForProfile(Profile* profile);

 protected:
  // Overridden from ProfileKeyedServiceFactory.
  virtual ProfileKeyedService* BuildServiceInstanceFor(
      Profile* profile) const OVERRIDE;

 private:
  friend struct DefaultSingletonTraits<WebHistoryServiceFactory>;

  explicit WebHistoryServiceFactory();
  virtual ~WebHistoryServiceFactory();

  DISALLOW_COPY_AND_ASSIGN(WebHistoryServiceFactory);
};

#endif  // CHROME_BROWSER_HISTORY_WEB_HISTORY_SERVICE_FACTORY_H_

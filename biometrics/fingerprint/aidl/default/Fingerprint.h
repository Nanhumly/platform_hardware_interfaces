/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <aidl/android/hardware/biometrics/fingerprint/BnFingerprint.h>

namespace aidl::android::hardware::biometrics::fingerprint {

class Fingerprint : public BnFingerprint {
  public:
    ndk::ScopedAStatus getSensorProps(std::vector<SensorProps>* _aidl_return) override;

    ndk::ScopedAStatus createSession(int32_t sensorId, int32_t userId,
                                     const std::shared_ptr<ISessionCallback>& cb,
                                     std::shared_ptr<ISession>* _aidl_return) override;

    ndk::ScopedAStatus setResetLockoutCallback(
            const std::shared_ptr<IResetLockoutCallback>& cb) override;

    ndk::ScopedAStatus generateChallenge(
            int32_t sensorId, int32_t userId, int32_t timeoutSec,
            const std::shared_ptr<IGenerateChallengeCallback>& cb) override;

    ndk::ScopedAStatus revokeChallenge(
            int32_t sensorId, int32_t userId,
            const std::shared_ptr<IRevokeChallengeCallback>& cb) override;
};

}  // namespace aidl::android::hardware::biometrics::fingerprint
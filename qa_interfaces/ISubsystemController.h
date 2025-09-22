/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2022 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"

namespace Thunder {
namespace QualityAssurance {

    // @json 1.0.0
    struct EXTERNAL ISubsystemController : virtual public Core::IUnknown {

        enum { ID = ID_SUBSYSTEMCONTROLLERPLUGIN};

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_SUBSYSTEMCONTROLLERPLUGIN_NOTIFICATION };

            // @brief Notifies of sampleRDKPlugin percentage change
            // @param percentage New percentage of sampleRDKPlugin in the "universal balance" (e.g. 50)
            virtual void SubsystemChanged() = 0;
        };

        virtual uint32_t Register(INotification* notification) = 0;
        virtual uint32_t Unregister(const INotification* notification) = 0;

        // @brief API to enable or disable subsystem
        // @detail enable = True - enables the subsystem, False - disables subsystem
        virtual uint32_t EnableSubsystem(const bool& enable) = 0;

        virtual uint32_t SubsystemStatus(bool& status /* @out */ ) const = 0;

    };

} // namespace Exchange

}

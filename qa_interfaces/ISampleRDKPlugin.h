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
    struct EXTERNAL ISampleRDKPlugin : virtual public Core::IUnknown {

        enum { ID = ID_SAMPLERDKPLUGIN};

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_SAMPLERDKPLUGIN_NOTIFICATION };

            // @brief Notifies of sampleRDKPlugin percentage change
            // @param percentage New percentage of sampleRDKPlugin in the "universal balance" (e.g. 50)
            virtual void SomePropertyChanged() = 0;
        };

        virtual uint32_t Register(INotification* notification) = 0;
        virtual uint32_t Unregister(const INotification* notification) = 0;

        // @property
        // @brief SomeProperty of sampleRDKPlugin
        // @detail Change of SomeProperty is persistent.
        virtual uint32_t SomeProperty(const uint8_t & value) = 0;
        virtual uint32_t SomeProperty(uint8_t& value /* @out */) const = 0;

        // @property
        // @brief Percentage of sampleRDKPlugin in the "universal balance" of the system
        // @details The Yin service is additionally required to change the yin/sampleRDKPlugin balance. 
        // @param percentage (e.g. 50)
        // @retval ERROR_BAD_REQUEST Given percentage value is invalid
        // @retval ERROR_UNAVAILABLE Can't set sampleRDKPlugin because yin is not available
        virtual uint32_t SomeDependentProperty(const uint8_t& value) = 0;
        virtual uint32_t SomeDependentProperty(uint8_t& value /* @out */) const = 0;

        // @json:omit
        virtual void Configure(PluginHost::IShell* service) = 0;
    };

} // namespace Exchange

}

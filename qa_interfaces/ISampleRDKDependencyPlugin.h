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
    struct EXTERNAL ISampleRDKDependencyPlugin : virtual public Core::IUnknown {

        enum { ID = ID_SAMPLERDKDEPENDENCYPLUGIN};

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_SAMPLERDKDEPENDENCYPLUGIN_NOTIFICATION };

            // @brief Notifies of sampleRDKPlugin percentage change
            // @param percentage New percentage of sampleRDKPlugin in the "universal balance" (e.g. 50)
            virtual void SlowNotification() = 0;
            virtual void FastNotification() = 0;
        };

        virtual Core::hresult Register(INotification* notification) = 0;
        virtual Core::hresult Unregister(const INotification* notification) = 0;

        // @property
        // @brief SomeProperty of sampleRDKPlugin
        // @detail Change of SomeProperty is persistent.
        virtual Core::hresult SlowProperty(const uint8_t & value) = 0;
        virtual Core::hresult SlowProperty(uint8_t& value /* @out */) const = 0;
        // @property
        // @brief FastProperty of sampleRDKPlugin
        // @detail Change of FastProperty is persistent.
        virtual Core::hresult FastProperty(const uint8_t & value) = 0;
        virtual Core::hresult FastProperty(uint8_t& value /* @out */) const = 0;

        // @brief Sets the delay for slow property
        // @alt setDelay
        virtual Core::hresult SetDelay(const uint16_t& delay) = 0;

        // @brief Sets the frequency for notification
        // @alt setNotificationFrequency
        virtual Core::hresult SetNotificationFrequency(const uint16_t& delay) = 0;
    };

} // namespace Exchange

}

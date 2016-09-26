/*
 * Copyright (C) 2010 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef InjectedBundleScriptWorld_h
#define InjectedBundleScriptWorld_h

#include "APIObject.h"
#include <wtf/PassRefPtr.h>
#include <wtf/RefPtr.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
    class DOMWrapperWorld;
}

namespace WebKit {

class InjectedBundleScriptWorld : public API::ObjectImpl<API::Object::Type::BundleScriptWorld> {
public:
    static Ref<InjectedBundleScriptWorld> create();
    static Ref<InjectedBundleScriptWorld> create(const String&);
    static PassRefPtr<InjectedBundleScriptWorld> getOrCreate(WebCore::DOMWrapperWorld&);
    static InjectedBundleScriptWorld* normalWorld();

    virtual ~InjectedBundleScriptWorld();

    const WebCore::DOMWrapperWorld& coreWorld() const;
    WebCore::DOMWrapperWorld& coreWorld();

    void clearWrappers();
    void makeAllShadowRootsOpen();

    const String& name() const { return m_name; }

private:
    InjectedBundleScriptWorld(WebCore::DOMWrapperWorld&, const String&);

    Ref<WebCore::DOMWrapperWorld> m_world;
    String m_name;
};

} // namespace WebKit

#endif // InjectedBundleScriptWorld_h

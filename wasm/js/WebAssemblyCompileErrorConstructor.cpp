/*
 * Copyright (C) 2016-2017 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "WebAssemblyCompileErrorConstructor.h"

#if ENABLE(WEBASSEMBLY)

#include "FunctionPrototype.h"
#include "JSCInlines.h"
#include "JSWebAssemblyCompileError.h"
#include "WebAssemblyCompileErrorPrototype.h"

#include "WebAssemblyCompileErrorConstructor.lut.h"

namespace JSC {

const ClassInfo WebAssemblyCompileErrorConstructor::s_info = { "Function", &Base::s_info, &constructorTableWebAssemblyCompileError, nullptr, CREATE_METHOD_TABLE(WebAssemblyCompileErrorConstructor) };

/* Source for WebAssemblyCompileErrorConstructor.lut.h
 @begin constructorTableWebAssemblyCompileError
 @end
 */

static EncodedJSValue JSC_HOST_CALL constructJSWebAssemblyCompileError(ExecState* exec)
{
    auto& vm = exec->vm();
    auto scope = DECLARE_THROW_SCOPE(vm);
    JSValue message = exec->argument(0);
    auto* structure = InternalFunction::createSubclassStructure(exec, exec->newTarget(), jsCast<InternalFunction*>(exec->jsCallee())->globalObject(vm)->WebAssemblyCompileErrorStructure());
    RETURN_IF_EXCEPTION(scope, encodedJSValue());
    return JSValue::encode(JSWebAssemblyCompileError::create(exec, vm, structure, message));
}

static EncodedJSValue JSC_HOST_CALL callJSWebAssemblyCompileError(ExecState* exec)
{
    JSValue message = exec->argument(0);
    Structure* errorStructure = jsCast<InternalFunction*>(exec->jsCallee())->globalObject(exec->vm())->WebAssemblyCompileErrorStructure();
    return JSValue::encode(ErrorInstance::create(exec, errorStructure, message, nullptr, TypeNothing, false));
}

WebAssemblyCompileErrorConstructor* WebAssemblyCompileErrorConstructor::create(VM& vm, Structure* structure, WebAssemblyCompileErrorPrototype* thisPrototype)
{
    auto* constructor = new (NotNull, allocateCell<WebAssemblyCompileErrorConstructor>(vm.heap)) WebAssemblyCompileErrorConstructor(vm, structure);
    constructor->finishCreation(vm, thisPrototype);
    return constructor;
}

Structure* WebAssemblyCompileErrorConstructor::createStructure(VM& vm, JSGlobalObject* globalObject, JSValue prototype)
{
    return Structure::create(vm, globalObject, prototype, TypeInfo(InternalFunctionType, StructureFlags), info());
}

void WebAssemblyCompileErrorConstructor::finishCreation(VM& vm, WebAssemblyCompileErrorPrototype* prototype)
{
    Base::finishCreation(vm, "CompileError"_s);
    putDirectWithoutTransition(vm, vm.propertyNames->prototype, prototype, PropertyAttribute::ReadOnly | PropertyAttribute::DontEnum | PropertyAttribute::DontDelete);
    putDirectWithoutTransition(vm, vm.propertyNames->length, jsNumber(1), PropertyAttribute::ReadOnly | PropertyAttribute::DontEnum | PropertyAttribute::DontDelete);
}

WebAssemblyCompileErrorConstructor::WebAssemblyCompileErrorConstructor(VM& vm, Structure* structure)
    : Base(vm, structure, callJSWebAssemblyCompileError, constructJSWebAssemblyCompileError)
{
}

} // namespace JSC

#endif // ENABLE(WEBASSEMBLY)

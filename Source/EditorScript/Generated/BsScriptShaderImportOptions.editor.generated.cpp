//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//************** Copyright (c) 2016-2019 Marko Pintera (marko.pintera@gmail.com). All rights reserved. *******************//
#include "BsScriptShaderImportOptions.editor.generated.h"
#include "BsMonoMethod.h"
#include "BsMonoClass.h"
#include "BsMonoUtil.h"
#include "../../bsf/Source/Foundation/bsfCore/Importer/BsShaderImportOptions.h"

namespace bs
{
	ScriptShaderImportOptions::ScriptShaderImportOptions(MonoObject* managedInstance, const SPtr<ShaderImportOptions>& value)
		:ScriptObject(managedInstance)
	{
		mInternal = value;
	}

	SPtr<ShaderImportOptions> ScriptShaderImportOptions::getInternal() const 
	{
		return std::static_pointer_cast<ShaderImportOptions>(mInternal);
	}

	void ScriptShaderImportOptions::initRuntimeData()
	{
		metaData.scriptClass->addInternalCall("Internal_setDefine", (void*)&ScriptShaderImportOptions::Internal_setDefine);
		metaData.scriptClass->addInternalCall("Internal_getDefine", (void*)&ScriptShaderImportOptions::Internal_getDefine);
		metaData.scriptClass->addInternalCall("Internal_hasDefine", (void*)&ScriptShaderImportOptions::Internal_hasDefine);
		metaData.scriptClass->addInternalCall("Internal_removeDefine", (void*)&ScriptShaderImportOptions::Internal_removeDefine);
		metaData.scriptClass->addInternalCall("Internal_getlanguages", (void*)&ScriptShaderImportOptions::Internal_getlanguages);
		metaData.scriptClass->addInternalCall("Internal_setlanguages", (void*)&ScriptShaderImportOptions::Internal_setlanguages);

	}

	MonoObject* ScriptShaderImportOptions::create(const SPtr<ShaderImportOptions>& value)
	{
		if(value == nullptr) return nullptr; 

		bool dummy = false;
		void* ctorParams[1] = { &dummy };

		MonoObject* managedInstance = metaData.scriptClass->createInstance("bool", ctorParams);
		new (bs_alloc<ScriptShaderImportOptions>()) ScriptShaderImportOptions(managedInstance, value);
		return managedInstance;
	}
	void ScriptShaderImportOptions::Internal_setDefine(ScriptShaderImportOptions* thisPtr, MonoString* define, MonoString* value)
	{
		String tmpdefine;
		tmpdefine = MonoUtil::monoToString(define);
		String tmpvalue;
		tmpvalue = MonoUtil::monoToString(value);
		thisPtr->getInternal()->setDefine(tmpdefine, tmpvalue);
	}

	bool ScriptShaderImportOptions::Internal_getDefine(ScriptShaderImportOptions* thisPtr, MonoString* define, MonoString** value)
	{
		bool tmp__output;
		String tmpdefine;
		tmpdefine = MonoUtil::monoToString(define);
		String tmpvalue;
		tmp__output = thisPtr->getInternal()->getDefine(tmpdefine, tmpvalue);

		bool __output;
		__output = tmp__output;
		MonoUtil::referenceCopy(value,  (MonoObject*)MonoUtil::stringToMono(tmpvalue));

		return __output;
	}

	bool ScriptShaderImportOptions::Internal_hasDefine(ScriptShaderImportOptions* thisPtr, MonoString* define)
	{
		bool tmp__output;
		String tmpdefine;
		tmpdefine = MonoUtil::monoToString(define);
		tmp__output = thisPtr->getInternal()->hasDefine(tmpdefine);

		bool __output;
		__output = tmp__output;

		return __output;
	}

	void ScriptShaderImportOptions::Internal_removeDefine(ScriptShaderImportOptions* thisPtr, MonoString* define)
	{
		String tmpdefine;
		tmpdefine = MonoUtil::monoToString(define);
		thisPtr->getInternal()->removeDefine(tmpdefine);
	}

	ShadingLanguageFlag ScriptShaderImportOptions::Internal_getlanguages(ScriptShaderImportOptions* thisPtr)
	{
		Flags<ShadingLanguageFlag> tmp__output;
		tmp__output = thisPtr->getInternal()->languages;

		ShadingLanguageFlag __output;
		__output = (ShadingLanguageFlag)(uint32_t)tmp__output;

		return __output;
	}

	void ScriptShaderImportOptions::Internal_setlanguages(ScriptShaderImportOptions* thisPtr, ShadingLanguageFlag value)
	{
		thisPtr->getInternal()->languages = value;
	}
}

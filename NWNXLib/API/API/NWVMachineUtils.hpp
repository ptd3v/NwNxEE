#pragma once
#include "nwn_api.hpp"

#include "CGameObject.hpp"
#include "CExoString.hpp"
#include "CScriptLocation.hpp"
#include "JsonEngineStructure.hpp"
#include "CNWSArea.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWVMachineUtils)
#endif

typedef int BOOL;

struct NWVMachineUtils
{
    static DataBlockRef SerializeToGff(CGameObject* o, BOOL bSaveObjectState);
    static CGameObject* DeserializeFromGff(DataViewRef d, BOOL bLoadObjectState, const CScriptLocation& loc, OBJECT_ID owner, const CExoString& sNewTag, BOOL bObjectCopy = false);
    static JsonEngineStructure SerializeToJson(CGameObject* o, BOOL bSaveObjectState);
    static CGameObject* DeserializeFromJson(const JsonEngineStructure& ob, BOOL bLoadObjectState, const CScriptLocation& loc, OBJECT_ID owner, const CExoString& sNewTag, BOOL bObjectCopy = false);
    static json StructToJson(CResGFF* gff, CResStruct* str, uint32_t nType);
    static void JsonToStruct(const json& ob, CResGFF* gff, CResStruct* str);
    static JsonEngineStructure SerializeToJson(const CResRef& r, RESTYPE t);
    static CNWSArea* SpawnScriptArea(CResGFF* areRoot, CResGFF* gitRoot, const CExoString& newTag = "", const CExoString& newName = "");

#ifdef NWN_CLASS_EXTENSION_NWVMachineUtils
    NWN_CLASS_EXTENSION_NWVMachineUtils
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWVMachineUtils)
#endif

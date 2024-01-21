// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject2/MyProject2GameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyProject2GameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	MYPROJECT2_API UClass* Z_Construct_UClass_AMyProject2GameModeBase();
	MYPROJECT2_API UClass* Z_Construct_UClass_AMyProject2GameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MyProject2();
// End Cross Module References
	void AMyProject2GameModeBase::StaticRegisterNativesAMyProject2GameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyProject2GameModeBase);
	UClass* Z_Construct_UClass_AMyProject2GameModeBase_NoRegister()
	{
		return AMyProject2GameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AMyProject2GameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyProject2GameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject2,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyProject2GameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MyProject2GameModeBase.h" },
		{ "ModuleRelativePath", "MyProject2GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyProject2GameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyProject2GameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyProject2GameModeBase_Statics::ClassParams = {
		&AMyProject2GameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMyProject2GameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyProject2GameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyProject2GameModeBase()
	{
		if (!Z_Registration_Info_UClass_AMyProject2GameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyProject2GameModeBase.OuterSingleton, Z_Construct_UClass_AMyProject2GameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyProject2GameModeBase.OuterSingleton;
	}
	template<> MYPROJECT2_API UClass* StaticClass<AMyProject2GameModeBase>()
	{
		return AMyProject2GameModeBase::StaticClass();
	}
	AMyProject2GameModeBase::AMyProject2GameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyProject2GameModeBase);
	AMyProject2GameModeBase::~AMyProject2GameModeBase() {}
	struct Z_CompiledInDeferFile_FID_Users_joe19_OneDrive_Documents_GitHub_TempleRunType_MyProject2_Source_MyProject2_MyProject2GameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joe19_OneDrive_Documents_GitHub_TempleRunType_MyProject2_Source_MyProject2_MyProject2GameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyProject2GameModeBase, AMyProject2GameModeBase::StaticClass, TEXT("AMyProject2GameModeBase"), &Z_Registration_Info_UClass_AMyProject2GameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyProject2GameModeBase), 473061043U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joe19_OneDrive_Documents_GitHub_TempleRunType_MyProject2_Source_MyProject2_MyProject2GameModeBase_h_3075581345(TEXT("/Script/MyProject2"),
		Z_CompiledInDeferFile_FID_Users_joe19_OneDrive_Documents_GitHub_TempleRunType_MyProject2_Source_MyProject2_MyProject2GameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joe19_OneDrive_Documents_GitHub_TempleRunType_MyProject2_Source_MyProject2_MyProject2GameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

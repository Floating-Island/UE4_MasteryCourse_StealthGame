// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPSGAME_FPSCharacter_generated_h
#error "FPSCharacter.generated.h already included, missing '#pragma once' in FPSCharacter.h"
#endif
#define FPSGAME_FPSCharacter_generated_h

#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_RPC_WRAPPERS \
	virtual bool serverFire_Validate(); \
	virtual void serverFire_Implementation(); \
 \
	DECLARE_FUNCTION(execserverFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->serverFire_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("serverFire_Validate")); \
			return; \
		} \
		P_THIS->serverFire_Implementation(); \
		P_NATIVE_END; \
	}


#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool serverFire_Validate(); \
	virtual void serverFire_Implementation(); \
 \
	DECLARE_FUNCTION(execserverFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!P_THIS->serverFire_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("serverFire_Validate")); \
			return; \
		} \
		P_THIS->serverFire_Implementation(); \
		P_NATIVE_END; \
	}


#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_EVENT_PARMS
#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_CALLBACK_WRAPPERS
#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSCharacter(); \
	friend struct Z_Construct_UClass_AFPSCharacter_Statics; \
public: \
	DECLARE_CLASS(AFPSCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSCharacter)


#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAFPSCharacter(); \
	friend struct Z_Construct_UClass_AFPSCharacter_Statics; \
public: \
	DECLARE_CLASS(AFPSCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSCharacter)


#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCharacter(AFPSCharacter&&); \
	NO_API AFPSCharacter(const AFPSCharacter&); \
public:


#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCharacter(AFPSCharacter&&); \
	NO_API AFPSCharacter(const AFPSCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSCharacter)


#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1PComponent() { return STRUCT_OFFSET(AFPSCharacter, Mesh1PComponent); } \
	FORCEINLINE static uint32 __PPO__GunMeshComponent() { return STRUCT_OFFSET(AFPSCharacter, GunMeshComponent); } \
	FORCEINLINE static uint32 __PPO__CameraComponent() { return STRUCT_OFFSET(AFPSCharacter, CameraComponent); } \
	FORCEINLINE static uint32 __PPO__noiseEmissionComponent() { return STRUCT_OFFSET(AFPSCharacter, noiseEmissionComponent); }


#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_19_PROLOG \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_EVENT_PARMS


#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_RPC_WRAPPERS \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_CALLBACK_WRAPPERS \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_INCLASS \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_CALLBACK_WRAPPERS \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_INCLASS_NO_PURE_DECLS \
	UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSGAME_API UClass* StaticClass<class AFPSCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UE4_MasteryCourse_StealthGame_Source_FPSGame_Public_FPSCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

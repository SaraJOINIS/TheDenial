#include "Laptop.h"

// Sets default values
ALaptop::ALaptop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	pSKLaptopMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SKLaptopMesh");
	RootComponent = pSKLaptopMesh;
}

// Called when the game starts or when spawned
void ALaptop::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaptop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaptop::SwitchLaptopScreen(bool bIsGoodBehavior)
{
	if (!IsValid(pSKLaptopMesh))
	{
		UE_LOG(LogTemp, Warning, TEXT("This laptop actor has no skeletal mesh."));
		return;
	}

	// 1 : index of the screen material (0: laptop plastic structure)
	UMaterialInterface* pMaterial = pSKLaptopMesh->GetMaterial(1);

	if (!IsValid(pMaterial))
	{
		UE_LOG(LogTemp, Warning, TEXT("Laptop is expected to have at least 2 materials."));
		return;
	}

	UMaterialInstanceDynamic* pDynMaterial = Cast<UMaterialInstanceDynamic>(pMaterial);

	if (!IsValid(pDynMaterial))
	{
		// Material has to be dynamic to modify BadIndex and IsGoodBehavior values
		pDynMaterial = UMaterialInstanceDynamic::Create(pMaterial, this);

		if (!IsValid(pDynMaterial))
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create dynamic material."));
			return;
		}

		pSKLaptopMesh->SetMaterial(1, pDynMaterial);
	}

	pDynMaterial->SetScalarParameterValue("IsGoodBehavior", bIsGoodBehavior ? 0.f : 1.f);

	// Draw a random number between 0 and 2 (lazy textures indexes)
	if (!bIsGoodBehavior)
	{
		int index = FMath::RandRange(0, 2);
		pDynMaterial->SetScalarParameterValue("BadIndex", index);
	}
}

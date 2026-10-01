#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Laptop.generated.h"

UCLASS()
class THEDENIAL_API ALaptop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaptop();

	// Macro enabling pSKLaptopMesh to be visible and editable from Unreal
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* pSKLaptopMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Macro enabling the function to be accessible in blueprint
	UFUNCTION(BlueprintCallable)
	void SwitchLaptopScreen(bool bIsGoodBehavior);
};

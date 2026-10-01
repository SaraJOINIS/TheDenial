#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AddRanking.generated.h"

UCLASS(BlueprintType)
class THEDENIAL_API UPlayerScoreObject : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "Score")
    FString PlayerName;

    UPROPERTY(BlueprintReadOnly, Category = "Score")
    int32 Score;
};

USTRUCT(BlueprintType)
struct FPlayerScoreStruct
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "Score")
    FString PlayerName;

    UPROPERTY(BlueprintReadOnly, Category = "Score")
    int32 Score;
};
UCLASS(Blueprintable)
class THEDENIAL_API UAddRanking : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Ranking")
    bool AddOrUpdatePlayerScore(const FString &PlayerName, int32 NewScore);

    UFUNCTION(BlueprintCallable, Category = "Ranking")
    TArray<UPlayerScoreObject *> GetTopPlayerScores();
};

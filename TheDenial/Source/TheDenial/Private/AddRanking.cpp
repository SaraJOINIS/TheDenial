#include "AddRanking.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Json.h"
#include "JsonUtilities.h"

/**
 * Adds a new player score or updates an existing player's score in the JSON file.
 *
 * @param PlayerName The name of the player to add or update.
 * @param NewScore The new score to save for the player.
 * @return true if the operation succeeded (file was written successfully), false otherwise.
 */
bool UAddRanking::AddOrUpdatePlayerScore(const FString &PlayerName, int32 NewScore)
{
    //UE_LOG(LogTemp, Warning, TEXT("Enter in AddOrUpdatePlayerScore"));
    FString FilePath = FPaths::ProjectContentDir() + TEXT("TheDenial/Data/ranking.json");
    FString JsonContent;

    TArray<TSharedPtr<FJsonValue>> Rankings;

    if (FPaths::FileExists(FilePath))
    {
        if (FFileHelper::LoadFileToString(JsonContent, *FilePath))
        {
            TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonContent);
            TSharedPtr<FJsonValue> JsonParsed;
            if (FJsonSerializer::Deserialize(Reader, JsonParsed) && JsonParsed->Type == EJson::Array)
            {
                Rankings = JsonParsed->AsArray();
            }
        }
    }

    bool bPlayerFound = false;
    for (auto &Entry : Rankings)
    {
        TSharedPtr<FJsonObject> Obj = Entry->AsObject();
        if (Obj->GetStringField("PlayerName") == PlayerName)
        {
            Obj->SetNumberField("Score", NewScore);
            bPlayerFound = true;
            break;
        }
    }

    if (!bPlayerFound)
    {
        TSharedPtr<FJsonObject> NewPlayer = MakeShareable(new FJsonObject);
        NewPlayer->SetStringField("Name", PlayerName + TEXT("Row")); // Exemple : "TiTiRow"
        NewPlayer->SetStringField("PlayerName", PlayerName);
        NewPlayer->SetNumberField("Score", NewScore);
        Rankings.Add(MakeShareable(new FJsonValueObject(NewPlayer)));
    }

    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonContent);
    FJsonSerializer::Serialize(Rankings, Writer);

    return FFileHelper::SaveStringToFile(JsonContent, *FilePath);
}

TArray<UPlayerScoreObject *> UAddRanking::GetTopPlayerScores()
{
        //UE_LOG(LogTemp, Warning, TEXT("Enter in GetTopPlayerScores"));
    FString FilePath = FPaths::ProjectContentDir() + TEXT("TheDenial/Data/ranking.json");
    FString JsonContent;
    TArray<UPlayerScoreObject *> TopScores;

    if (!FPaths::FileExists(FilePath))
    {
        return TopScores;
    }

    if (!FFileHelper::LoadFileToString(JsonContent, *FilePath))
    {
        return TopScores;
    }

    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonContent);
    TSharedPtr<FJsonValue> JsonParsed;

    if (FJsonSerializer::Deserialize(Reader, JsonParsed) && JsonParsed->Type == EJson::Array)
    {
        TArray<TSharedPtr<FJsonValue>> Rankings = JsonParsed->AsArray();

        Rankings.Sort([](const TSharedPtr<FJsonValue> &A, const TSharedPtr<FJsonValue> &B)
                      {
            int32 ScoreA = A->AsObject()->GetIntegerField(TEXT("Score"));
            int32 ScoreB = B->AsObject()->GetIntegerField(TEXT("Score"));
            return ScoreA > ScoreB; });

        int32 Count = FMath::Min(10, Rankings.Num());
        for (int32 i = 0; i < Count; ++i)
        {
            TSharedPtr<FJsonObject> Obj = Rankings[i]->AsObject();
            FString PlayerName = Obj->GetStringField(TEXT("PlayerName"));
            int32 Score = Obj->GetIntegerField(TEXT("Score"));

            UPlayerScoreObject *NewScoreObj = NewObject<UPlayerScoreObject>();
            NewScoreObj->PlayerName = PlayerName;
            NewScoreObj->Score = Score;

            TopScores.Add(NewScoreObj);
        }
    }

    return TopScores;
}

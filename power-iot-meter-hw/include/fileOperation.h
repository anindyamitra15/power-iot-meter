#ifndef _fileOperation_H_
#define _fileOperation_H_
#include <SPIFFS.h>
/* You only need to format SPIFFS the first time you run a
   test or else use the SPIFFS plugin to create a partition
   https://github.com/me-no-dev/arduino-esp32fs-plugin */
#define FORMAT_SPIFFS_IF_FAILED true

void initFileSystem()
{
    if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        while (1)
            ;
    }
}

void listDir(fs::FS &fs, const char *dirname = "/", uint8_t levels = 0)
{
    Serial.printf("Listing directory: %s\r\n", dirname);

    File root = fs.open(dirname);
    if (!root)
    {
        Serial.println(F("Failed to open directory"));
        return;
    }
    if (!root.isDirectory())
    {
        Serial.println(F("Chosen path isn't a directory"));
        root.close();
        return;
    }

    File file = root.openNextFile();
    while (file)
    {
        if (file.isDirectory())
        {
            Serial.print(F("  DIR : "));
            Serial.println(file.name());
            if (levels)
            {
                listDir(fs, file.name(), levels - 1);
            }
        }
        else
        {
            Serial.print(F("  FILE: "));
            Serial.print(file.name());
            Serial.print(F("\tSIZE: "));
            Serial.println(file.size());
        }
        file.close();
        file = root.openNextFile();
    }
}

void readFile(fs::FS &fs, const char *path)
{
    Serial.printf("Reading file: %s\r\n", path);

    File file = fs.open(path);
    if (!file || file.isDirectory())
    {
        Serial.println(F("Failed to open file for reading"));
        return;
    }

    Serial.println(F("Reading file:"));
    while (file.available())
    {
        Serial.write(file.read());
    }
    file.close();
}

void writeFile(fs::FS &fs, const char *path, const char *message)
{
    Serial.printf("Writing file: %s\r\n", path);

    File file = fs.open(path, FILE_WRITE);
    if (!file)
    {
        Serial.println(F("Failed to open file for writing"));
        return;
    }
    if (file.print(message) || strlen(message) < 1)
    {
        Serial.println(F("File written!"));
    }
    else
    {
        Serial.println(F("File write failed"));
    }
    file.close();
}

void appendFile(fs::FS &fs, const char *path, const char *message)
{
    Serial.printf("Appending to file: %s\r\n", path);

    File file = fs.open(path, FILE_APPEND);
    if (!file)
    {
        Serial.println(F("Failed to open file for appending"));
        return;
    }
    if (file.print(message))
    {
        Serial.println(F("Update appended!"));
    }
    else
    {
        Serial.println(F("Appending failed"));
    }
    file.close();
}

void renameFile(fs::FS &fs, const char *path1, const char *path2)
{
    Serial.printf("Renaming file %s to %s\r\n", path1, path2);
    if (fs.rename(path1, path2))
    {
        Serial.println(F("File renamed!"));
    }
    else
    {
        Serial.println(F("Renaming failed"));
    }
}

void deleteFile(fs::FS &fs, const char *path)
{
    Serial.printf("Deleting file: %s\r\n", path);
    if (fs.remove(path))
    {
        Serial.println(F("File deleted!"));
    }
    else
    {
        Serial.println(F("Deletion failed"));
    }
}

#endif
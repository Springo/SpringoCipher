/**
 * Created by Kevin on 2/18/2016.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SpringoCipher.h"
#define START 32
#define SIZE 94

char* encryptText(char* text, char* key) {
	if (key == NULL || text == NULL || *key == '\0')
		return NULL;
	char* keystart = key;
	char* encrypted = (char*)malloc(strlen(text) + 1);
	while (text != '\0') {
		*encrypted = getTrueValue(*text + *key);
		key++;
		if (*key == '\0')
			key = keystart;
		text++;
		encrypted++;
	}
	return encrypted;
}

char* decryptText(char* text, char* key) {
	if (key == NULL || text == NULL || *key == '\0')
		return NULL;
	char* keystart = key;
	char* decrypted = (char*)malloc(strlen(text) + 1);
	while (text != '\0') {
		*decrypted = getRangeValue(getRawValue(*text) - *key);
		key++;
		if (*key == '\0')
			key = keystart;
		text++;
		decrypted++;
	}
	return decrypted;
}

char getTrueValue(char raw) {
	return START + (raw % SIZE);
}

char getRawValue(char enc) {
	char rawenc = enc - START;
	if (rawenc < 32)
		return (rawenc + SIZE);
	return rawenc;
}

char getRangeValue(char value) {
	char newvalue = value;
	while (newvalue < START || newvalue >= (SIZE + START))
		newvalue += SIZE;
	return newvalue;
}


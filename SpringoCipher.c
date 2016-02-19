/**
 * Created by Kevin on 2/18/2016.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SpringoCipher.h"
#define START 32
#define SIZE 94

int main(int argv, char** argc) {
	if (argv != 4 || strlen(argc[1]) > 1 || !(*argc[1] == 'e' || *argc[1] == 'd')) {
		printf("Format: SpringoCipher <e/d> <message> <key>\n");
		printf("e: encrypt, d: decrypt\n");
		printf("Use backslashes to escape spaces. (E.g. Hello\\ World)\n");
		return 0;
	}
	char* output = "ERROR";
	if (*argc[1] == 'e') {
		if ((output = encryptText(argc[2], argc[3])) == NULL) {
			printf("Error");
			return 1;
		}
	}
	else {
		if ((output = decryptText(argc[2], argc[3])) == NULL) {
			printf("Error");
			return 1;
		}
	}
	printf("Output: %s\n", output);
	return 0;
}

char* encryptText(char* text, char* key) {
	if (key == NULL || text == NULL || *key == '\0')
		return NULL;
	char* keystart = key;
	char* encrypted = (char*)malloc(strlen(text) + 1);
	char* encstart = encrypted;
	while (*text) {
		*encrypted = (char)getTrueValue(((int)*text + (int)*key));
		key++;
		if (*key == '\0')
			key = keystart;
		text++;
		encrypted++;
	}
	*encrypted = '\0';
	return encstart;
}

char* decryptText(char* text, char* key) {
	if (key == NULL || text == NULL || *key == '\0')
		return NULL;
	char* keystart = key;
	char* decrypted = (char*)malloc(strlen(text) + 1);
	char* decstart = decrypted;
	while (*text) {
		*decrypted = (char)getRangeValue(getRawValue((int)*text) - (int)*key);
		key++;
		if (*key == '\0')
			key = keystart;
		text++;
		decrypted++;
	}
	*decrypted = '\0';
	return decstart;
}

int getTrueValue(int raw) {
	return START + (raw % SIZE);
}

int getRawValue(int enc) {
	int rawenc = enc - START;
	if (rawenc < 32)
		return (rawenc + SIZE);
	return rawenc;
}

int getRangeValue(int value) {
	int newvalue = value;
	while (newvalue < START || newvalue >= (SIZE + START))
		newvalue += SIZE;
	return newvalue;
}


#include <iostream>

using namespace std;

class EncryptionTecnique {
public:
    virtual char* encrypt(const char* msg) = 0;
    virtual char* decrypt(const char* msg) = 0;
    virtual ~EncryptionTecnique() {}
};

class EncryptionTecnique1 : public EncryptionTecnique {
public:
    char* encrypt(const char* msg) override {
        int len = 0;
        while (msg[len] != '\0') {
            len++;
        }

        char* result = new char[len * 2 + 1];
        int index = 0;

        for (int i = 0; i < len; ++i) {
            char c = msg[i];
            
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }
            
            int ascii = (int)c;
            
            result[index++] = (ascii / 10) + '0';
            result[index++] = (ascii % 10) + '0';
        }
        result[index] = '\0';
        
        return result;
    }

    char* decrypt(const char* msg) override {
        int len = 0;
        while (msg[len] != '\0') {
            len++;
        }

        char* result = new char[len / 2 + 1];
        int index = 0;

        for (int i = 0; i < len; i += 2) {
            if (i + 1 < len) {
                int tens = msg[i] - '0';
                int ones = msg[i + 1] - '0';
                int ascii = (tens * 10) + ones;
                
                result[index++] = (char)ascii;
            }
        }
        result[index] = '\0';
        
        return result;
    }
};

class EncryptionTecnique2 : public EncryptionTecnique {
public:
    char* encrypt(const char* msg) override {
        int len = 0;
        while (msg[len] != '\0') {
            len++;
        }

        char* result = new char[len * 2 + 1];
        int index = 0;

        for (int i = 0; i < len; ++i) {
            char c = msg[i];
            
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }
            
            int ascii = (int)c + 2;
            
            result[index++] = (ascii / 10) + '0';
            result[index++] = (ascii % 10) + '0';
        }
        result[index] = '\0';
        
        return result;
    }

    char* decrypt(const char* msg) override {
        int len = 0;
        while (msg[len] != '\0') {
            len++;
        }

        char* result = new char[len / 2 + 1];
        int index = 0;

        for (int i = 0; i < len; i += 2) {
            if (i + 1 < len) {
                int tens = msg[i] - '0';
                int ones = msg[i + 1] - '0';
                int ascii = ((tens * 10) + ones) - 2;
                
                result[index++] = (char)ascii;
            }
        }
        result[index] = '\0';
        
        return result;
    }
};

int main() {
    const char* input = "Hello";
    
    EncryptionTecnique* tech1 = new EncryptionTecnique1();
    EncryptionTecnique* tech2 = new EncryptionTecnique2();
    
    char* enc1 = tech1->encrypt(input);
    char* dec1 = tech1->decrypt(enc1);
    
    char* enc2 = tech2->encrypt(input);
    char* dec2 = tech2->decrypt(enc2);
    
    cout << "Original String: " << input << "\n\n";
    
    cout << "--- Technique 1 ---\n";
    cout << "Encrypted: " << enc1 << "\n";
    cout << "Decrypted: " << dec1 << "\n\n";
    
    cout << "--- Technique 2 ---\n";
    cout << "Encrypted: " << enc2 << "\n";
    cout << "Decrypted: " << dec2 << "\n";
    
    delete[] enc1;
    delete[] dec1;
    delete[] enc2;
    delete[] dec2;
    
    delete tech1;
    delete tech2;
    
    return 0;
}
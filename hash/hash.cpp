#include <cryptopp/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <iostream>
using namespace CryptoPP;
using namespace std;

int main() {
    cout << "'MD5 HASH Algorithm'" << endl;
    string msgg, msg, result, result1;
    FileSource("test.txt", true, new StringSink(msg));
    msg.resize(msg.size() - 1);
    cout << "\nТекст из файла: " << msg << endl;
    HexEncoder encoder(new StringSink(result));
    Weak::MD5 hash;
    hash.Update((const byte*)&msg[0], msg.size());
    msgg.resize(hash.DigestSize());
    hash.Final((byte*)&msgg[0]);
    cout << "HASH: ";
    StringSource(msgg, true, new Redirector(encoder));
    cout << result << "\n\n";
    
    //Блок для проверки работоспособности кода, написанного выше
    HexEncoder encoder1(new StringSink(result1));
    string msgg1, msg1 = "Milk inside a bag of milk inside a bag of milk";
    cout << "Текст из тестового модуля: " << msg1 << endl;
    hash.Update((const byte*)&msg1[0], msg1.size());
    msgg1.resize(hash.DigestSize());
    hash.Final((byte*)&msgg1[0]);
    cout << "HASH: ";
    StringSource(msgg1, true, new Redirector(encoder1));
    cout << result1 << endl;
    if (result == result1)
        cout << "\nТест успешно пройден!\n\n";
}

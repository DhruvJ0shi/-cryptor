#include "Caesar.h"
#include <iostream>

int main()
{
	Cryptor::Caesar  caesar;
	caesar.Message()->SetMsg( std::string( "Hello World!" ) );
	caesar.SetKey( 7 );
	caesar.SetSymbols( std::string( "abcdefghijklmnopqrstuvwxyz" ) );
	caesar.AddSymbols( std::string( "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ) );

	std::cout << "The Message is: "		<< caesar.Message()->GetMsg() << std::endl;
	std::cout << "The Key is: "			<< caesar.GetKey() << std::endl;
	std::cout << "The Symbols are: "	<< caesar.GetSymbols() << std::endl;

	// Encryption code
	caesar.Encrypt();
	std::cout << "The Encrypted message: " << caesar.NewMessage()->GetMsg() << std::endl;

	// Decryption code
	caesar.Message()->SetMsg( caesar.NewMessage()->GetMsg() );
	caesar.SetMode( Cryptor::Mode::DECRYPT );
	caesar.Decrypt();
	std::cout << "The Decrypted message: " << caesar.NewMessage()->GetMsg() << std::endl;

	getchar();

	return 0;
}

#include "Caesar.h"

Cryptor::Caesar::Caesar( const std::string& msg, int key, const std::string& symbols, Cryptor::Mode mode )
{
	Message()->SetMsg( msg );
	m_symbols = symbols;
	SetKey( key );
	SetMode( mode );
}

void Cryptor::Caesar::Encrypt()
{
	if( this->GetMode() == Cryptor::Mode::ENCRYPT )
	{
		std::string tmpMsg;
		char symbol;
		int index;

		for( int i = 0; i < Message()->GetMsgLength(); i++ )
		{
			symbol = Message()->GetMsg().at( i );
			if( m_symbols.find( symbol ) != std::string::npos )
			{
				index = m_symbols.find_first_of( symbol );
				index += GetKey();

				if( index >= m_symbols.size() )
					index -= m_symbols.size();

				tmpMsg.push_back( m_symbols.at( index ) );
			}
			else
			{
				tmpMsg.push_back( symbol );
			}
		}

		NewMessage()->SetMsg( tmpMsg );
	}
	else
	{
		Decrypt();
	}
}

void Cryptor::Caesar::Decrypt()
{
	if( this->GetMode() == Cryptor::Mode::DECRYPT )
	{
		std::string tmpMsg;
		char symbol;
		int index;

		for( int i = 0; i < Message()->GetMsgLength(); i++ )
		{
			symbol = Message()->GetMsg().at( i );
			if( m_symbols.find( symbol ) != std::string::npos )
			{
				index = m_symbols.find_first_of( symbol );
				index -= GetKey();

				if( index < 0 )
				{
					index += m_symbols.size();
				}

				tmpMsg.push_back( m_symbols.at( index ) );
			}
			else
			{
				tmpMsg.push_back( symbol );
			}
		}

		NewMessage()->SetMsg( tmpMsg );
	}
	else
	{
		Encrypt();
	}
}

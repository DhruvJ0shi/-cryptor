#pragma once
#ifndef CAESAR_INCLUDED_H
#define CAESAR_INCLUDED_H

#include "Cipher.h"

namespace Cryptor
{
	class Caesar: public Cipher
	{
	public:
		Caesar( const std::string& msg = std::string(),
				int key = 0,
				const std::string& symbols = std::string(),
				Cryptor::Mode mode = Cryptor::Mode::ENCRYPT );

		void Encrypt();
		void Decrypt();

		const inline void SetSymbols( const std::string& symbols ) { m_symbols = symbols; }
		inline std::string GetSymbols() { return m_symbols; }
		const inline void AddSymbols( const std::string& newSymbols ) { m_symbols.append( newSymbols ); }
	private:
		std::string m_symbols;
	};
}

#endif

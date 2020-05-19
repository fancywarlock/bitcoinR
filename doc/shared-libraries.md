Shared Libraries
================

## bitcoinrconsensus

The purpose of this library is to make the verification functionality that is critical to bitcoinR's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `bitcoinrconsensus.h` located in  `src/script/bitcoinrconsensus.h`.

#### Version

`bitcoinrconsensus_version` returns an `unsigned int` with the API version *(currently at an experimental `0`)*.

#### Script Validation

`bitcoinrconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `bitcoinrconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `bitcoinrconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `bitcoinrconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/bitcoinr/bips/blob/master/bip-0016.mediawiki)) subscripts
- `bitcoinrconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/bitcoinr/bips/blob/master/bip-0066.mediawiki)) compliance
- `bitcoinrconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/bitcoinr/bips/blob/master/bip-0147.mediawiki))
- `bitcoinrconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/bitcoinr/bips/blob/master/bip-0065.mediawiki))
- `bitcoinrconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/bitcoinr/bips/blob/master/bip-0112.mediawiki))
- `bitcoinrconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/bitcoinr/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `bitcoinrconsensus_ERR_OK` - No errors with input parameters *(see the return value of `bitcoinrconsensus_verify_script` for the verification status)*
- `bitcoinrconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `bitcoinrconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `bitcoinrconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `bitcoinrconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NbitcoinR](https://github.com/NicolasDorier/NbitcoinR/blob/master/NbitcoinR/Script.cs#L814) (.NET Bindings)
- [node-libbitcoinrconsensus](https://github.com/bitpay/node-libbitcoinrconsensus) (Node.js Bindings)
- [java-libbitcoinrconsensus](https://github.com/dexX7/java-libbitcoinrconsensus) (Java Bindings)
- [bitcoinrconsensus-php](https://github.com/Bit-Wasp/bitcoinrconsensus-php) (PHP Bindings)

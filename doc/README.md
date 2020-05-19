bitcoinR Core
=============

Setup
---------------------
bitcoinR Core is the original bitcoinR client and it builds the backbone of the network. It downloads and, by default, stores the entire history of bitcoinR transactions (which is currently more than 100 GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download bitcoinR Core, visit [bitcoinrcore.org](https://bitcoinrcore.org/en/releases/).

Running
---------------------
The following are some helpful notes on how to run bitcoinR Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/bitcoinr-qt` (GUI) or
- `bin/bitcoinrd` (headless)

### Windows

Unpack the files into a directory, and then run bitcoinr-qt.exe.

### macOS

Drag bitcoinR Core to your applications folder, and then run bitcoinR Core.

### Need Help?

* See the documentation at the [bitcoinR Wiki](https://en.bitcoinr.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#bitcoinr](http://webchat.freenode.net?channels=bitcoinr) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=bitcoinr).
* Ask for help on the [bitcoinRTalk](https://bitcoinrtalk.org/) forums, in the [Technical Support board](https://bitcoinrtalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build bitcoinR Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The bitcoinR repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/bitcoinr/doxygen/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Travis CI](travis-ci.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the [bitcoinRTalk](https://bitcoinrtalk.org/) forums, in the [Development & Technical Discussion board](https://bitcoinrtalk.org/index.php?board=6.0).
* Discuss project-specific development on #bitcoinr-core-dev on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=bitcoinr-core-dev).
* Discuss general bitcoinR development on #bitcoinr-dev on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=bitcoinr-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.

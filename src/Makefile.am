# Copyright (c) 2013-2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS) $(GPROF_LDFLAGS) $(SANITIZER_LDFLAGS)
AM_CXXFLAGS = $(DEBUG_CXXFLAGS) $(HARDENED_CXXFLAGS) $(WARN_CXXFLAGS) $(NOWARN_CXXFLAGS) $(ERROR_CXXFLAGS) $(GPROF_CXXFLAGS) $(SANITIZER_CXXFLAGS)
AM_CPPFLAGS = $(DEBUG_CPPFLAGS) $(HARDENED_CPPFLAGS)
AM_LIBTOOLFLAGS = --preserve-dup-deps
EXTRA_LIBRARIES =

if EMBEDDED_UNIVALUE
LIBUNIVALUE = univalue/libunivalue.la

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
else
LIBUNIVALUE = $(UNIVALUE_LIBS)
endif

BITCOINR_INCLUDES=-I$(builddir) $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

BITCOINR_INCLUDES += -I$(srcdir)/secp256k1/include
BITCOINR_INCLUDES += $(UNIVALUE_CFLAGS)

LIBBITCOINR_SERVER=libbitcoinr_server.a
LIBBITCOINR_COMMON=libbitcoinr_common.a
LIBBITCOINR_CONSENSUS=libbitcoinr_consensus.a
LIBBITCOINR_CLI=libbitcoinr_cli.a
LIBBITCOINR_UTIL=libbitcoinr_util.a
LIBBITCOINR_CRYPTO_BASE=crypto/libbitcoinr_crypto_base.a
LIBBITCOINRQT=qt/libbitcoinrqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

if ENABLE_ZMQ
LIBBITCOINR_ZMQ=libbitcoinr_zmq.a
endif
if BUILD_BITCOINR_LIBS
LIBBITCOINRCONSENSUS=libbitcoinrconsensus.la
endif
if ENABLE_WALLET
LIBBITCOINR_WALLET=libbitcoinr_wallet.a
endif

LIBBITCOINR_CRYPTO= $(LIBBITCOINR_CRYPTO_BASE)
if ENABLE_SSE41
LIBBITCOINR_CRYPTO_SSE41 = crypto/libbitcoinr_crypto_sse41.a
LIBBITCOINR_CRYPTO += $(LIBBITCOINR_CRYPTO_SSE41)
endif
if ENABLE_AVX2
LIBBITCOINR_CRYPTO_AVX2 = crypto/libbitcoinr_crypto_avx2.a
LIBBITCOINR_CRYPTO += $(LIBBITCOINR_CRYPTO_AVX2)
endif
if ENABLE_SHANI
LIBBITCOINR_CRYPTO_SHANI = crypto/libbitcoinr_crypto_shani.a
LIBBITCOINR_CRYPTO += $(LIBBITCOINR_CRYPTO_SHANI)
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*.h) $(wildcard secp256k1/src/*.c) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBBITCOINR_CRYPTO) \
  $(LIBBITCOINR_UTIL) \
  $(LIBBITCOINR_COMMON) \
  $(LIBBITCOINR_CONSENSUS) \
  $(LIBBITCOINR_SERVER) \
  $(LIBBITCOINR_CLI) \
  $(LIBBITCOINR_WALLET) \
  $(LIBBITCOINR_ZMQ)

lib_LTLIBRARIES = $(LIBBITCOINRCONSENSUS)

bin_PROGRAMS =
noinst_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_BITCOINRD
  bin_PROGRAMS += bitcoinrd
endif

if BUILD_BITCOINR_UTILS
  bin_PROGRAMS += bitcoinr-cli bitcoinr-tx
endif

.PHONY: FORCE check-symbols check-security
# bitcoinr core #
BITCOINR_CORE_H = \
  addrdb.h \
  addrman.h \
  base58.h \
  bech32.h \
  bloom.h \
  blockencodings.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coins.h \
  compat.h \
  compat/byteswap.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  consensus/consensus.h \
  consensus/tx_verify.h \
  core_io.h \
  core_memusage.h \
  cuckoocache.h \
  fs.h \
  httprpc.h \
  httpserver.h \
  index/base.h \
  index/txindex.h \
  indirectmap.h \
  init.h \
  interfaces/handler.h \
  interfaces/node.h \
  interfaces/wallet.h \
  key.h \
  key_io.h \
  keystore.h \
  dbwrapper.h \
  limitedmap.h \
  logging.h \
  memusage.h \
  merkleblock.h \
  miner.h \
  net.h \
  net_processing.h \
  netaddress.h \
  netbase.h \
  netmessagemaker.h \
  noui.h \
  outputtype.h \
  policy/feerate.h \
  policy/fees.h \
  policy/policy.h \
  policy/rbf.h \
  pow.h \
  protocol.h \
  random.h \
  reverse_iterator.h \
  reverselock.h \
  rpc/blockchain.h \
  rpc/client.h \
  rpc/mining.h \
  rpc/protocol.h \
  rpc/server.h \
  rpc/rawtransaction.h \
  rpc/register.h \
  rpc/util.h \
  scheduler.h \
  script/descriptor.h \
  script/ismine.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  shutdown.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/events.h \
  support/lockedpool.h \
  sync.h \
  threadsafety.h \
  threadinterrupt.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  undo.h \
  util.h \
  utilmemory.h \
  utilmoneystr.h \
  utiltime.h \
  validation.h \
  validationinterface.h \
  versionbits.h \
  walletinitinterface.h \
  wallet/coincontrol.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/feebumper.h \
  wallet/fees.h \
  wallet/rpcwallet.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  wallet/walletutil.h \
  wallet/coinselection.h \
  warnings.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqconfig.h\
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h \
  zmq/zmqrpc.h


obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh "$(abs_top_builddir)/src/obj/build.h" \
	  "$(abs_top_srcdir)"
libbitcoinr_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between bitcoinrd and bitcoinr-qt
libbitcoinr_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOINR_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
libbitcoinr_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitcoinr_server_a_SOURCES = \
  addrdb.cpp \
  addrman.cpp \
  bloom.cpp \
  blockencodings.cpp \
  chain.cpp \
  checkpoints.cpp \
  consensus/tx_verify.cpp \
  httprpc.cpp \
  httpserver.cpp \
  index/base.cpp \
  index/txindex.cpp \
  init.cpp \
  dbwrapper.cpp \
  merkleblock.cpp \
  miner.cpp \
  net.cpp \
  net_processing.cpp \
  noui.cpp \
  outputtype.cpp \
  policy/fees.cpp \
  policy/policy.cpp \
  policy/rbf.cpp \
  pow.cpp \
  rest.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/server.cpp \
  rpc/util.cpp \
  script/sigcache.cpp \
  shutdown.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txmempool.cpp \
  ui_interface.cpp \
  validation.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(BITCOINR_CORE_H)

if ENABLE_ZMQ
libbitcoinr_zmq_a_CPPFLAGS = $(BITCOINR_INCLUDES) $(ZMQ_CFLAGS)
libbitcoinr_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitcoinr_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp \
  zmq/zmqrpc.cpp
endif


# wallet: shared between bitcoinrd and bitcoinr-qt, but only linked
# when wallet enabled
libbitcoinr_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOINR_INCLUDES)
libbitcoinr_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitcoinr_wallet_a_SOURCES = \
  interfaces/wallet.cpp \
  wallet/coincontrol.cpp \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/feebumper.cpp \
  wallet/fees.cpp \
  wallet/init.cpp \
  wallet/rpcdump.cpp \
  wallet/rpcwallet.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  wallet/walletutil.cpp \
  wallet/coinselection.cpp \
  $(BITCOINR_CORE_H)

# crypto primitives library
crypto_libbitcoinr_crypto_base_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libbitcoinr_crypto_base_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libbitcoinr_crypto_base_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/chacha20.h \
  crypto/chacha20.cpp \
  crypto/common.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha512.cpp \
  crypto/sha512.h

if USE_ASM
crypto_libbitcoinr_crypto_base_a_SOURCES += crypto/sha256_sse4.cpp
endif

crypto_libbitcoinr_crypto_sse41_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libbitcoinr_crypto_sse41_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libbitcoinr_crypto_sse41_a_CXXFLAGS += $(SSE41_CXXFLAGS)
crypto_libbitcoinr_crypto_sse41_a_CPPFLAGS += -DENABLE_SSE41
crypto_libbitcoinr_crypto_sse41_a_SOURCES = crypto/sha256_sse41.cpp

crypto_libbitcoinr_crypto_avx2_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libbitcoinr_crypto_avx2_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libbitcoinr_crypto_avx2_a_CXXFLAGS += $(AVX2_CXXFLAGS)
crypto_libbitcoinr_crypto_avx2_a_CPPFLAGS += -DENABLE_AVX2
crypto_libbitcoinr_crypto_avx2_a_SOURCES = crypto/sha256_avx2.cpp

crypto_libbitcoinr_crypto_shani_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libbitcoinr_crypto_shani_a_CPPFLAGS = $(AM_CPPFLAGS)
crypto_libbitcoinr_crypto_shani_a_CXXFLAGS += $(SHANI_CXXFLAGS)
crypto_libbitcoinr_crypto_shani_a_CPPFLAGS += -DENABLE_SHANI
crypto_libbitcoinr_crypto_shani_a_SOURCES = crypto/sha256_shani.cpp

# consensus: shared between all executables that validate any consensus rules.
libbitcoinr_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOINR_INCLUDES)
libbitcoinr_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitcoinr_consensus_a_SOURCES = \
  amount.h \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/validation.h \
  hash.cpp \
  hash.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/bitcoinrconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
  span.h \
  tinyformat.h \
  uint256.cpp \
  uint256.h \
  utilstrencodings.cpp \
  utilstrencodings.h \
  version.h

# common: shared between bitcoinrd, and bitcoinr-qt and non-server tools
libbitcoinr_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOINR_INCLUDES)
libbitcoinr_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitcoinr_common_a_SOURCES = \
  base58.cpp \
  bech32.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  core_read.cpp \
  core_write.cpp \
  key.cpp \
  key_io.cpp \
  keystore.cpp \
  netaddress.cpp \
  netbase.cpp \
  policy/feerate.cpp \
  protocol.cpp \
  scheduler.cpp \
  script/descriptor.cpp \
  script/ismine.cpp \
  script/sign.cpp \
  script/standard.cpp \
  warnings.cpp \
  $(BITCOINR_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libbitcoinr_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOINR_INCLUDES)
libbitcoinr_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitcoinr_util_a_SOURCES = \
  support/lockedpool.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  fs.cpp \
  interfaces/handler.cpp \
  interfaces/node.cpp \
  logging.cpp \
  random.cpp \
  rpc/protocol.cpp \
  support/cleanse.cpp \
  sync.cpp \
  threadinterrupt.cpp \
  util.cpp \
  utilmoneystr.cpp \
  utilstrencodings.cpp \
  utiltime.cpp \
  $(BITCOINR_CORE_H)

if GLIBC_BACK_COMPAT
libbitcoinr_util_a_SOURCES += compat/glibc_compat.cpp
AM_LDFLAGS += $(COMPAT_LDFLAGS)
endif

# cli: shared between bitcoinr-cli and bitcoinr-qt
libbitcoinr_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOINR_INCLUDES)
libbitcoinr_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libbitcoinr_cli_a_SOURCES = \
  rpc/client.cpp \
  $(BITCOINR_CORE_H)

nodist_libbitcoinr_util_a_SOURCES = $(srcdir)/obj/build.h
#

# bitcoinrd binary #
bitcoinrd_SOURCES = bitcoinrd.cpp
bitcoinrd_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOINR_INCLUDES)
bitcoinrd_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
bitcoinrd_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
bitcoinrd_SOURCES += bitcoinrd-res.rc
endif

bitcoinrd_LDADD = \
  $(LIBBITCOINR_SERVER) \
  $(LIBBITCOINR_WALLET) \
  $(LIBBITCOINR_COMMON) \
  $(LIBUNIVALUE) \
  $(LIBBITCOINR_UTIL) \
  $(LIBBITCOINR_ZMQ) \
  $(LIBBITCOINR_CONSENSUS) \
  $(LIBBITCOINR_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

bitcoinrd_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS)

# bitcoinr-cli binary #
bitcoinr_cli_SOURCES = bitcoinr-cli.cpp
bitcoinr_cli_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOINR_INCLUDES) $(EVENT_CFLAGS)
bitcoinr_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
bitcoinr_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
bitcoinr_cli_SOURCES += bitcoinr-cli-res.rc
endif

bitcoinr_cli_LDADD = \
  $(LIBBITCOINR_CLI) \
  $(LIBUNIVALUE) \
  $(LIBBITCOINR_UTIL) \
  $(LIBBITCOINR_CRYPTO)

bitcoinr_cli_LDADD += $(BOOST_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# bitcoinr-tx binary #
bitcoinr_tx_SOURCES = bitcoinr-tx.cpp
bitcoinr_tx_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOINR_INCLUDES)
bitcoinr_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
bitcoinr_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
bitcoinr_tx_SOURCES += bitcoinr-tx-res.rc
endif

bitcoinr_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBBITCOINR_COMMON) \
  $(LIBBITCOINR_UTIL) \
  $(LIBBITCOINR_CONSENSUS) \
  $(LIBBITCOINR_CRYPTO) \
  $(LIBSECP256K1)

bitcoinr_tx_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS)
#

# bitcoinrconsensus library #
if BUILD_BITCOINR_LIBS
include_HEADERS = script/bitcoinrconsensus.h
libbitcoinrconsensus_la_SOURCES = $(crypto_libbitcoinr_crypto_base_a_SOURCES) $(libbitcoinr_consensus_a_SOURCES)

if GLIBC_BACK_COMPAT
  libbitcoinrconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

libbitcoinrconsensus_la_LDFLAGS = $(AM_LDFLAGS) -no-undefined $(RELDFLAGS)
libbitcoinrconsensus_la_LIBADD = $(LIBSECP256K1)
libbitcoinrconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_BITCOINR_INTERNAL
libbitcoinrconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES = $(EXTRA_LIBRARIES)

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno
CLEANFILES += obj/build.h

EXTRA_DIST = $(CTAES_DIST)


config/bitcoinr-config.h: config/stamp-h1
	@$(MAKE) -C $(top_builddir) $(subdir)/$(@)
config/stamp-h1: $(top_srcdir)/$(subdir)/config/bitcoinr-config.h.in $(top_builddir)/config.status
	$(AM_V_at)$(MAKE) -C $(top_builddir) $(subdir)/$(@)
$(top_srcdir)/$(subdir)/config/bitcoinr-config.h.in:  $(am__configure_deps)
	$(AM_V_at)$(MAKE) -C $(top_srcdir) $(subdir)/config/bitcoinr-config.h.in

clean-local:
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -f config.h
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

check-symbols: $(bin_PROGRAMS)
if GLIBC_BACK_COMPAT
	@echo "Checking glibc back compat..."
	$(AM_V_at) READELF=$(READELF) CPPFILT=$(CPPFILT) $(top_srcdir)/contrib/devtools/symbol-check.py < $(bin_PROGRAMS)
endif

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) READELF=$(READELF) OBJDUMP=$(OBJDUMP) $(top_srcdir)/contrib/devtools/security-check.py < $(bin_PROGRAMS)
endif

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(<D) $<

if EMBEDDED_LEVELDB
include Makefile.leveldb.include
endif

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif

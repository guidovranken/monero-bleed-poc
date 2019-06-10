# monero-bleed-poc

Get the current production Monero release:

```sh
wget https://github.com/monero-project/monero/archive/v0.14.0.2.tar.gz
tar zxf v0.14.0.2.tar.gz
```

Build:

```sh
clang++ poc.cpp monero-0.14.0.2/external/easylogging++/easylogging++.cc -I monero-0.14.0.2/contrib/epee/include/ -I monero-0.14.0.2/external/easylogging++/ -I monero-0.14.0.2/src/ -lboost_system -lpthread -lcrypto
```

or

```sh
clang++ -fsanitize=memory -fsanitize-memory-track-origins -fPIE -pie -fno-omit-frame-pointer -g poc.cpp monero-0.14.0.2/external/easylogging++/easylogging++.cc -I monero-0.14.0.2/contrib/epee/include/ -I monero-0.14.0.2/external/easylogging++/ -I monero-0.14.0.2/src/ -lboost_system -lpthread -lcrypto
```

This proof-of-concept isolates the behavior seen in a number of functions in ```src/wallet2/wallet2.cpp```, eg.

```cpp
 2288 void wallet2::update_pool_state(bool refreshed)
 2289 {
 2290   MDEBUG("update_pool_state start");
 2291
 2292   auto keys_reencryptor = epee::misc_utils::create_scope_leave_handler([&, this]() {
 2293     if (m_encrypt_keys_after_refresh)
 2294     {
 2295       encrypt_keys(*m_encrypt_keys_after_refresh);
 2296       m_encrypt_keys_after_refresh = boost::none;
 2297     }
 2298   });
 2299
 2300   // get the pool state
 2301   cryptonote::COMMAND_RPC_GET_TRANSACTION_POOL_HASHES_BIN::request req;
 2302   cryptonote::COMMAND_RPC_GET_TRANSACTION_POOL_HASHES_BIN::response res;
 2303   m_daemon_rpc_mutex.lock();
 2304   bool r = epee::net_utils::invoke_http_json("/get_transaction_pool_hashes.bin", req, res, m_http_client, rpc_timeout);
```

The request (```req```) variable is not initialized and its contents will be formatted into JSON and sent to the peer. This can be a problem if the client is connecting to a non-local daemon or bootstrap node.

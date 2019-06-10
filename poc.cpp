/* Guido Vranken <guidovranken@gmail.com> */

#include <net/http_client.h>
#include <rpc/core_rpc_server_commands_defs.h>
#include <storages/http_abstract_invoke.h>

template <class T>
static void invoke_http_json(void)
{
    typename T::request ireq;
    typename T::response ires;

    std::string req_param;
    if(!epee::serialization::store_t_to_json(ireq, req_param)) {
        return;
    }

    printf("%s\n", req_param.c_str());
}

int main(void)
{
    while ( true ) {
        const unsigned char which = rand() % 64;
        switch ( which ) {
            case 0:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_HEIGHT>();
                break;
            case 1:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_BLOCKS_FAST>();
                break;
            case 2:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_BLOCKS_BY_HEIGHT>();
                break;
            case 3:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_ALT_BLOCKS_HASHES>();
                break;
            case 4:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_HASHES_FAST>();
                break;
            case 5:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_ADDRESS_TXS>();
                break;
            case 6:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_ADDRESS_INFO>();
                break;
            case 7:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_UNSPENT_OUTS>();
                break;
            case 8:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_RANDOM_OUTS>();
                break;
            case 9:
                invoke_http_json<cryptonote::COMMAND_RPC_SUBMIT_RAW_TX>();
                break;
            case 10:
                invoke_http_json<cryptonote::COMMAND_RPC_LOGIN>();
                break;
            case 11:
                invoke_http_json<cryptonote::COMMAND_RPC_IMPORT_WALLET_REQUEST>();
                break;
            case 12:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_TRANSACTIONS>();
                break;
            case 13:
                invoke_http_json<cryptonote::COMMAND_RPC_IS_KEY_IMAGE_SPENT>();
                break;
            case 14:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_TX_GLOBAL_OUTPUTS_INDEXES>();
                break;
            case 15:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_OUTPUTS_BIN>();
                break;
            case 16:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_OUTPUTS>();
                break;
            case 17:
                invoke_http_json<cryptonote::COMMAND_RPC_SEND_RAW_TX>();
                break;
            case 18:
                invoke_http_json<cryptonote::COMMAND_RPC_START_MINING>();
                break;
            case 19:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_INFO>();
                break;
            case 20:
                invoke_http_json<cryptonote::COMMAND_RPC_STOP_MINING>();
                break;
            case 21:
                invoke_http_json<cryptonote::COMMAND_RPC_MINING_STATUS>();
                break;
            case 22:
                invoke_http_json<cryptonote::COMMAND_RPC_SAVE_BC>();
                break;
            case 25:
                invoke_http_json<cryptonote::COMMAND_RPC_GETBLOCKTEMPLATE>();
                break;
            case 27:
                invoke_http_json<cryptonote::COMMAND_RPC_GENERATEBLOCKS>();
                break;
            case 28:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_LAST_BLOCK_HEADER>();
                break;
            case 29:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_BLOCK_HEADER_BY_HASH>();
                break;
            case 30:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_BLOCK_HEADER_BY_HEIGHT>();
                break;
            case 31:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_BLOCK>();
                break;
            case 32:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_PEER_LIST>();
                break;
            case 33:
                invoke_http_json<cryptonote::COMMAND_RPC_SET_LOG_HASH_RATE>();
                break;
            case 34:
                invoke_http_json<cryptonote::COMMAND_RPC_SET_LOG_LEVEL>();
                break;
            case 35:
                invoke_http_json<cryptonote::COMMAND_RPC_SET_LOG_CATEGORIES>();
                break;
            case 36:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_TRANSACTION_POOL>();
                break;
            case 37:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_TRANSACTION_POOL_HASHES_BIN>();
                break;
            case 38:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_TRANSACTION_POOL_HASHES>();
                break;
            case 39:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_TRANSACTION_POOL_BACKLOG>();
                break;
            case 40:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_TRANSACTION_POOL_STATS>();
                break;
            case 41:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_CONNECTIONS>();
                break;
            case 42:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_BLOCK_HEADERS_RANGE>();
                break;
            case 43:
                invoke_http_json<cryptonote::COMMAND_RPC_STOP_DAEMON>();
                break;
            case 44:
                invoke_http_json<cryptonote::COMMAND_RPC_FAST_EXIT>();
                break;
            case 45:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_LIMIT>();
                break;
            case 46:
                invoke_http_json<cryptonote::COMMAND_RPC_SET_LIMIT>();
                break;
            case 47:
                invoke_http_json<cryptonote::COMMAND_RPC_OUT_PEERS>();
                break;
            case 48:
                invoke_http_json<cryptonote::COMMAND_RPC_IN_PEERS>();
                break;
            case 49:
                invoke_http_json<cryptonote::COMMAND_RPC_START_SAVE_GRAPH>();
                break;
            case 50:
                invoke_http_json<cryptonote::COMMAND_RPC_STOP_SAVE_GRAPH>();
                break;
            case 51:
                invoke_http_json<cryptonote::COMMAND_RPC_HARD_FORK_INFO>();
                break;
            case 52:
                invoke_http_json<cryptonote::COMMAND_RPC_GETBANS>();
                break;
            case 53:
                invoke_http_json<cryptonote::COMMAND_RPC_SETBANS>();
                break;
            case 54:
                invoke_http_json<cryptonote::COMMAND_RPC_FLUSH_TRANSACTION_POOL>();
                break;
            case 55:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_OUTPUT_HISTOGRAM>();
                break;
            case 56:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_VERSION>();
                break;
            case 57:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_COINBASE_TX_SUM>();
                break;
            case 58:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_BASE_FEE_ESTIMATE>();
                break;
            case 59:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_ALTERNATE_CHAINS>();
                break;
            case 60:
                invoke_http_json<cryptonote::COMMAND_RPC_UPDATE>();
                break;
            case 61:
                invoke_http_json<cryptonote::COMMAND_RPC_RELAY_TX>();
                break;
            case 62:
                invoke_http_json<cryptonote::COMMAND_RPC_SYNC_INFO>();
                break;
            case 63:
                invoke_http_json<cryptonote::COMMAND_RPC_GET_OUTPUT_DISTRIBUTION>();
                break;
        }
    }

    return 0;
}

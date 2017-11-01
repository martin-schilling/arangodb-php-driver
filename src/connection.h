/**
 *  Include guard
 */
#pragma once

/**
 *  Dependencies
 */
#include <phpcpp.h>
#include <stdlib.h>
#include <fuerte/fuerte.h>

namespace f = ::arangodb::fuerte;

/**
 *  Start namespace
 */
namespace ArangoDb {


enum ConnectionOptions {
    HOST = 0,
    USER = 1,
    PASSWORD = 2,
    MAX_CHUNK_SIZE = 3,
    VST_VERSION = 4,
    ON_FAILURE = 5
};

/**
 *  Class definition
 */
class Connection :
    public Php::Base
{
private:
    /**
     *  The underlying connection object
     *  @var    std::shared_ptr<f::Connection>
     */
    std::shared_ptr<f::Connection> _connection;

    /**
     *  The underlying event loop service object
     *  @var    std::unique_ptr<f::EventLoopService>
     */
    std::unique_ptr<f::EventLoopService> _eventLoopService;

//    Php::Array _options;
    std::map<std::string,std::string> _options;
public:
    Connection() = default;

    /**
     *  Constructor
     *
     *  @param  Php::Parameters  connection options
     */
    void __construct(Php::Parameters &params);

    /**
     * Connect to database
     */
    void connect();

    virtual ~Connection() = default;
};

/**
 *  End namespace
 */
}

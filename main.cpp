#include <iostream>
#include "HandleWriting.h"
#include "StartScreen.h"
#include <string>
#include "cpprest/http_client.h"
#include "cpprest/filestream.h"
#include "cpprest/base_uri.h"
#include "HandleMode.h"

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace web::json;

using namespace utility;

// Verify a license key using the validate-key action
pplx::task <http_response> validate_license_key(http_client client, const string license_key)
{
    http_request req;

    value meta;
    meta["key"] = value::string(license_key);

    value body;
    body["meta"] = meta;

    req.headers().add("Content-Type", "application/vnd.api+json");
    req.headers().add("Accept", "application/json");

    req.set_request_uri(uri("/licenses/actions/validate-key"));
    req.set_method(methods::POST);
    req.set_body(body.serialize());

    return client.request(req);
}


int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "[ERROR] " << "No license key argument specified" << std::endl;
        exit(1);
    }
    StartScreen::PrintStartScreen();
    HandleMode::init_mode();
    return 0;
}





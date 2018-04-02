set(libs
    mbedtls)


set(targets
    client
    server
    client_cc
    server_cc)

add_executable(client client.c)
target_link_libraries(client ${libs})

add_executable(server server.c)
target_link_libraries(server ${libs})

add_executable(client_cc client_cust_cipher.c)
target_link_libraries(client_cc ${libs})

add_executable(server_cc server_cust_cipher.c)
target_link_libraries(server_cc ${libs})

add_executable(ciphersuites_list ciphersuites_list.c)
target_link_libraries(ciphersuites_list ${libs})


add_executable(client_cc_lf client_cc_large_file.c)
target_link_libraries(client_cc_lf ${libs})

add_executable(server_cc_lf server_cc_large_file.c)
target_link_libraries(server_cc_lf ${libs})

install(TARGETS ${targets}
        DESTINATION "bin"
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

message(WARNING "CMAKE_C_FLAGS_DEBUG is ${CMAKE_C_FLAGS_DEBUG}")
message(WARNING "CMAKE_C_FLAGS is ${CMAKE_C_FLAGS}")

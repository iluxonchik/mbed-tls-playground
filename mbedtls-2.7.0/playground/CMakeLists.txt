set(libs
    mbedtls)


set(targets
    client
    server)

add_executable(client client.c)
target_link_libraries(client ${libs})

add_executable(server server.c)
target_link_libraries(server ${libs})

install(TARGETS ${targets}
        DESTINATION "bin"
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

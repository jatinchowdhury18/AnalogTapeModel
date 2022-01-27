find_package(Git)

if (Git_FOUND)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            OUTPUT_VARIABLE GIT_BRANCH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
            COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            OUTPUT_VARIABLE GIT_COMMIT_HASH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endif ()

if ("${GIT_BRANCH}" STREQUAL "")
    message(WARNING "Could not determine Git branch, using placeholder.")
    set(GIT_BRANCH "git-no-branch")
endif ()
if ("${GIT_COMMIT_HASH}" STREQUAL "")
    message(WARNING "Could not determine Git commit hash, using placeholder.")
    set(GIT_COMMIT_HASH "git-no-commit")
endif ()

cmake_host_system_information(RESULT PLUGIN_BUILD_FQDN QUERY FQDN)

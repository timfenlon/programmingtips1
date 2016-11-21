# add headers and source files
#SET (${PROJECT_NAME}_h main.h)
#SET (${PROJECT_NAME}_src main.c)
SET(proj-src logging.h logging.c linkedlist.h linkedlist.c)

# Create the executable
# -----------------
#ADD_EXECUTABLE( ${PROJECT_NAME} ${PROJECT_NAME}_h ${PROJECT_NAME}_src )
ADD_EXECUTABLE( ${PROJECT_NAME} main.c ${proj-src})


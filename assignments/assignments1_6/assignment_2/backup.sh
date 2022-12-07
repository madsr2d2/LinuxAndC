
#! /usr/bin/bash
PORT="22222"
DIR=$(pwd)
DEST="student@130.225.170.80:/home/student/backup_folder"
VERBOSE=0
# Get arguments
while getopts vp:s:d: OPTION  
do
	case "$OPTION" in
		p) PORT="$OPTARG" ;;
		s) DIR="$OPTARG" ;;
		d) DEST="$OPTARG" ;;
		v) VERBOSE=1 ;;
		?) echo "script usage: $(basename $0) [-p port] [-s source_directory] [-d server:destination_folder] [-v verbose]" >&2 exit 1 ;;
	esac
done

# Set Archive name
ARCHIVE_NAME=/tmp/$(basename $DIR).tar.gz

# Creat and Compress TAR archive
if [ $VERBOSE -eq 1 ]
then
	echo "Creating TAR archive from $DIR and compressing archive to $ARCHIVE_NAME"
	tar -cvzf $ARCHIVE_NAME $DIR
	echo "... done!"
else
	tar -czf $ARCHIVE_NAME $DIR
fi

# Send compressed TAR archive
if [ $VERBOSE -eq 1 ]
then
	echo ""
	echo "Sending $ARCHIVE_NAME to $DEST on port $PORT"
	rsync -v -e "ssh -p $PORT" $ARCHIVE_NAME $DEST
	echo "... done!"
else
	rsync -e "ssh -p $PORT" $ARCHIVE_NAME $DEST
fi

# Remove compressed TAR archive
if [ $VERBOSE -eq 1 ]
then
	echo ""
	echo "Removing $ARCHIVE_NAME from local machine"
	rm $ARCHIVE_NAME
	echo "... done!"
else
	rm $ARCHIVE_NAME
fi
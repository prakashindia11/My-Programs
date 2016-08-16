while true
do

echo "1 List partition tables"
echo "2 Mount a device"
echo "3 Unmount a device"
echo "4 Exit"
echo "Enter a choice : "
read choice

case $choice in

1) sudo fdisk -l
   ;;

2) sudo fdisk -l
   
   echo "Enter the name of the device to be mounted from the above list : "
   read dev
   echo "Enter the path where the device is to be mounted : "
   echo path

   sudo mount $dev $path
   ;;

3) sudo fdisk -l
   echo "Enter the name of the device to be unmounted from the above list : "
   read dev

   sudo umount $dev
   ;;

4) exit
   ;;

*) echo "Please enter a proper value."

esac
done

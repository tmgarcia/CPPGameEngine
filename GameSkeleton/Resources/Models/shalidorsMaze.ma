//Maya ASCII 2012 scene
//Name: shalidorsMaze.ma
//Last modified: Mon, May 05, 2014 10:47:38 PM
//Codeset: 1252
requires maya "2012";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2012";
fileInfo "version" "2012 x64";
fileInfo "cutIdentifier" "001200000000-796618";
fileInfo "osv" "Microsoft Windows 7 Enterprise Edition, 64-bit Windows 7 Service Pack 1 (Build 7601)\n";
fileInfo "license" "education";
createNode transform -n "Mesh";
createNode transform -n "polySurface1" -p "Mesh";
createNode transform -n "transform87" -p "polySurface1";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape1" -p "transform87";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface2" -p "Mesh";
createNode transform -n "transform86" -p "polySurface2";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape2" -p "transform86";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface3" -p "Mesh";
createNode transform -n "transform85" -p "polySurface3";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape3" -p "transform85";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface4" -p "Mesh";
createNode transform -n "transform84" -p "polySurface4";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape4" -p "transform84";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface5" -p "Mesh";
createNode transform -n "transform83" -p "polySurface5";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape5" -p "transform83";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface6" -p "Mesh";
createNode transform -n "transform82" -p "polySurface6";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape6" -p "transform82";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface7" -p "Mesh";
createNode transform -n "transform81" -p "polySurface7";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape7" -p "transform81";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface8" -p "Mesh";
createNode transform -n "transform80" -p "polySurface8";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape8" -p "transform80";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface9" -p "Mesh";
createNode transform -n "transform79" -p "polySurface9";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape9" -p "transform79";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface10" -p "Mesh";
createNode transform -n "transform78" -p "polySurface10";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape10" -p "transform78";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface11" -p "Mesh";
createNode transform -n "transform77" -p "polySurface11";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape11" -p "transform77";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface12" -p "Mesh";
createNode transform -n "transform76" -p "polySurface12";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape12" -p "transform76";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface13" -p "Mesh";
createNode transform -n "transform75" -p "polySurface13";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape13" -p "transform75";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface14" -p "Mesh";
createNode transform -n "transform74" -p "polySurface14";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape14" -p "transform74";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface15" -p "Mesh";
createNode transform -n "transform73" -p "polySurface15";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape15" -p "transform73";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface16" -p "Mesh";
createNode transform -n "transform72" -p "polySurface16";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape16" -p "transform72";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface17" -p "Mesh";
createNode transform -n "transform71" -p "polySurface17";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape17" -p "transform71";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface18" -p "Mesh";
createNode transform -n "transform70" -p "polySurface18";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape18" -p "transform70";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface19" -p "Mesh";
createNode transform -n "transform69" -p "polySurface19";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape19" -p "transform69";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface20" -p "Mesh";
createNode transform -n "transform68" -p "polySurface20";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape20" -p "transform68";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface21" -p "Mesh";
createNode transform -n "transform67" -p "polySurface21";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape21" -p "transform67";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface22" -p "Mesh";
createNode transform -n "transform66" -p "polySurface22";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape22" -p "transform66";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface23" -p "Mesh";
createNode transform -n "transform65" -p "polySurface23";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape23" -p "transform65";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface24" -p "Mesh";
createNode transform -n "transform64" -p "polySurface24";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape24" -p "transform64";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface25" -p "Mesh";
createNode transform -n "transform63" -p "polySurface25";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape25" -p "transform63";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface26" -p "Mesh";
createNode transform -n "transform62" -p "polySurface26";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape26" -p "transform62";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface27" -p "Mesh";
createNode transform -n "transform61" -p "polySurface27";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape27" -p "transform61";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface28" -p "Mesh";
createNode transform -n "transform60" -p "polySurface28";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape28" -p "transform60";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface29" -p "Mesh";
createNode transform -n "transform59" -p "polySurface29";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape29" -p "transform59";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface30" -p "Mesh";
createNode transform -n "transform58" -p "polySurface30";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape30" -p "transform58";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface31" -p "Mesh";
createNode transform -n "transform57" -p "polySurface31";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape31" -p "transform57";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface32" -p "Mesh";
createNode transform -n "transform56" -p "polySurface32";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape32" -p "transform56";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface33" -p "Mesh";
createNode transform -n "transform55" -p "polySurface33";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape33" -p "transform55";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface34" -p "Mesh";
createNode transform -n "transform54" -p "polySurface34";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape34" -p "transform54";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface35" -p "Mesh";
createNode transform -n "transform53" -p "polySurface35";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape35" -p "transform53";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface36" -p "Mesh";
createNode transform -n "transform52" -p "polySurface36";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape36" -p "transform52";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface37" -p "Mesh";
createNode transform -n "transform51" -p "polySurface37";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape37" -p "transform51";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface38" -p "Mesh";
createNode transform -n "transform50" -p "polySurface38";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape38" -p "transform50";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface39" -p "Mesh";
createNode transform -n "transform49" -p "polySurface39";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape39" -p "transform49";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface40" -p "Mesh";
createNode transform -n "transform48" -p "polySurface40";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape40" -p "transform48";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface41" -p "Mesh";
createNode transform -n "transform47" -p "polySurface41";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape41" -p "transform47";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface42" -p "Mesh";
createNode transform -n "transform46" -p "polySurface42";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape42" -p "transform46";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface43" -p "Mesh";
createNode transform -n "transform45" -p "polySurface43";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape43" -p "transform45";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface44" -p "Mesh";
createNode transform -n "transform44" -p "polySurface44";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape44" -p "transform44";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface45" -p "Mesh";
createNode transform -n "transform43" -p "polySurface45";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape45" -p "transform43";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface46" -p "Mesh";
createNode transform -n "transform42" -p "polySurface46";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape46" -p "transform42";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface47" -p "Mesh";
createNode transform -n "transform41" -p "polySurface47";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape47" -p "transform41";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface48" -p "Mesh";
createNode transform -n "transform40" -p "polySurface48";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape48" -p "transform40";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface49" -p "Mesh";
createNode transform -n "transform39" -p "polySurface49";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape49" -p "transform39";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface50" -p "Mesh";
createNode transform -n "transform38" -p "polySurface50";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape50" -p "transform38";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface51" -p "Mesh";
createNode transform -n "transform37" -p "polySurface51";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape51" -p "transform37";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface52" -p "Mesh";
createNode transform -n "transform36" -p "polySurface52";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape52" -p "transform36";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface53" -p "Mesh";
createNode transform -n "transform35" -p "polySurface53";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape53" -p "transform35";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface54" -p "Mesh";
createNode transform -n "transform34" -p "polySurface54";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape54" -p "transform34";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface55" -p "Mesh";
createNode transform -n "transform33" -p "polySurface55";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape55" -p "transform33";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface56" -p "Mesh";
createNode transform -n "transform32" -p "polySurface56";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape56" -p "transform32";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface57" -p "Mesh";
createNode transform -n "transform31" -p "polySurface57";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape57" -p "transform31";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface58" -p "Mesh";
createNode transform -n "transform30" -p "polySurface58";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape58" -p "transform30";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface59" -p "Mesh";
createNode transform -n "transform29" -p "polySurface59";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape59" -p "transform29";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface60" -p "Mesh";
createNode transform -n "transform28" -p "polySurface60";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape60" -p "transform28";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface61" -p "Mesh";
createNode transform -n "transform27" -p "polySurface61";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape61" -p "transform27";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface62" -p "Mesh";
createNode transform -n "transform26" -p "polySurface62";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape62" -p "transform26";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface63" -p "Mesh";
createNode transform -n "transform25" -p "polySurface63";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape63" -p "transform25";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface64" -p "Mesh";
createNode transform -n "transform24" -p "polySurface64";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape64" -p "transform24";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface65" -p "Mesh";
createNode transform -n "transform23" -p "polySurface65";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape65" -p "transform23";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface66" -p "Mesh";
createNode transform -n "transform22" -p "polySurface66";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape66" -p "transform22";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface67" -p "Mesh";
createNode transform -n "transform21" -p "polySurface67";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape67" -p "transform21";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface68" -p "Mesh";
createNode transform -n "transform20" -p "polySurface68";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape68" -p "transform20";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface69" -p "Mesh";
createNode transform -n "transform19" -p "polySurface69";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape69" -p "transform19";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface70" -p "Mesh";
createNode transform -n "transform18" -p "polySurface70";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape70" -p "transform18";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface71" -p "Mesh";
createNode transform -n "transform17" -p "polySurface71";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape71" -p "transform17";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface72" -p "Mesh";
createNode transform -n "transform16" -p "polySurface72";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape72" -p "transform16";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface73" -p "Mesh";
createNode transform -n "transform15" -p "polySurface73";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape73" -p "transform15";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface74" -p "Mesh";
createNode transform -n "transform14" -p "polySurface74";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape74" -p "transform14";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface75" -p "Mesh";
createNode transform -n "transform13" -p "polySurface75";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape75" -p "transform13";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface76" -p "Mesh";
createNode transform -n "transform12" -p "polySurface76";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape76" -p "transform12";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface77" -p "Mesh";
createNode transform -n "transform11" -p "polySurface77";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape77" -p "transform11";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface78" -p "Mesh";
createNode transform -n "transform10" -p "polySurface78";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape78" -p "transform10";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface79" -p "Mesh";
createNode transform -n "transform9" -p "polySurface79";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape79" -p "transform9";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface80" -p "Mesh";
createNode transform -n "transform8" -p "polySurface80";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape80" -p "transform8";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface81" -p "Mesh";
createNode transform -n "transform7" -p "polySurface81";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape81" -p "transform7";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface82" -p "Mesh";
createNode transform -n "transform6" -p "polySurface82";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape82" -p "transform6";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface83" -p "Mesh";
createNode transform -n "transform5" -p "polySurface83";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape83" -p "transform5";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface84" -p "Mesh";
createNode transform -n "transform4" -p "polySurface84";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape84" -p "transform4";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface85" -p "Mesh";
createNode transform -n "transform3" -p "polySurface85";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape85" -p "transform3";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "polySurface86" -p "Mesh";
createNode transform -n "transform2" -p "polySurface86";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape86" -p "transform2";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "transform1" -p "Mesh";
	setAttr ".v" no;
createNode mesh -n "MeshShape" -p "transform1";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:287]";
	setAttr ".pv" -type "double2" 0.5 0.2051393473520875 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 540 ".uvst[0].uvsp";
	setAttr ".uvst[0].uvsp[0:249]" -type "float2" 0.0027266443 0.0052243322 0.99727333
		 0.0052243322 0.0027266443 0.40505436 0.99727333 0.40505436 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.5391019 0.41781506
		 0.98492682 0.41781506 0.5391019 0.99052346 0.98492682 0.99052346 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.5391019 0.41781506
		 0.98492682 0.41781506 0.5391019 0.99052346 0.98492682 0.99052346 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.5391019 0.41781506
		 0.98492682 0.41781506 0.5391019 0.99052346 0.98492682 0.99052346 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.5391019 0.41781506
		 0.98492682 0.41781506 0.5391019 0.99052346 0.98492682 0.99052346 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.75590837 0.3878029 0.75590837 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.99274147
		 0.3878029 0.99274147 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.75590837
		 0.3878029 0.75590837 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147
		 0.3878029 0.99274147 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147
		 0.3878029 0.99274147 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.75590837 0.3878029 0.75590837 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.99274147
		 0.3878029 0.99274147 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.75590837
		 0.3878029 0.75590837 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147
		 0.3878029 0.99274147 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147
		 0.3878029 0.99274147 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.75590837 0.3878029 0.75590837 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.75590837
		 0.3878029 0.75590837 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.5391019 0.41781506
		 0.98492682 0.41781506 0.5391019 0.99052346 0.98492682 0.99052346 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.5391019 0.41781506
		 0.98492682 0.41781506 0.5391019 0.99052346 0.98492682 0.99052346 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.49610728 0.50389278 0.007258594 0.99274147 0.49610728 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.5391019 0.41781506
		 0.98492682 0.41781506 0.5391019 0.99052346 0.98492682 0.99052346 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278
		 0.3878029 0.50389278;
	setAttr ".uvst[0].uvsp[250:499]" 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.5391019 0.41781506 0.98492682 0.41781506 0.5391019 0.99052346 0.98492682 0.99052346
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.75590837 0.3878029 0.75590837
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278 0.3878029 0.50389278
		 0.007258594 0.75590837 0.3878029 0.75590837 0.007258594 0.50389278 0.3878029 0.50389278
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278 0.3878029 0.50389278
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.75590837 0.3878029 0.75590837
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278 0.3878029 0.50389278
		 0.007258594 0.75590837 0.3878029 0.75590837 0.007258594 0.50389278 0.3878029 0.50389278
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278 0.3878029 0.50389278
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.62047434 0.3878029 0.62047434
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.75590837 0.3878029 0.75590837 0.007258594 0.50389278 0.3878029 0.50389278
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.75590837 0.3878029 0.75590837
		 0.007258594 0.99274147 0.3878029 0.99274147 0.5391019 0.41781506 0.98492682 0.41781506
		 0.5391019 0.99052346 0.98492682 0.99052346 0.5391019 0.71306276 0.98492682 0.71306276
		 0.5391019 0.99052346 0.98492682 0.99052346 0.5391019 0.41781506 0.98492682 0.41781506
		 0.5391019 0.99052346 0.98492682 0.99052346 0.007258594 0.75590837 0.3878029 0.75590837
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278 0.3878029 0.50389278
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.75590837 0.3878029 0.75590837
		 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278 0.007258594 0.99274147
		 0.3878029 0.50389278 0.3878029 0.99274147 0.007258594 0.75590837 0.007258594 0.8140775
		 0.3878029 0.75590837 0.3878029 0.8140775 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.8112911 0.3878029 0.8112911
		 0.007258594 0.90191674 0.3878029 0.90191674 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.75590837 0.3878029 0.75590837 0.007258594 0.99274147 0.3878029 0.99274147
		 0.5391019 0.41781506 0.5391019 0.99052346 0.98492682 0.41781506 0.98492682 0.99052346
		 0.5391019 0.71306276 0.5391019 0.99052346 0.98492682 0.71306276 0.98492682 0.99052346
		 0.007258594 0.50389278 0.007258594 0.99274147 0.3878029 0.50389278 0.3878029 0.99274147
		 0.007258594 0.75590837 0.007258594 0.99274147 0.3878029 0.75590837 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.8112911 0.3878029 0.8112911
		 0.007258594 0.90191674 0.3878029 0.90191674 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.49610728 0.50389278 0.007258594 0.99274147 0.49610728 0.99274147
		 0.007258594 0.50389278 0.49610728 0.50389278 0.007258594 0.99274147 0.49610728 0.99274147
		 0.007258594 0.50389278 0.49610728 0.50389278 0.007258594 0.99274147 0.49610728 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.75590837 0.3878029 0.75590837
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594 0.99274147 0.3878029 0.99274147
		 0.007258594 0.99274147 0.3878029 0.99274147 0.5391019 0.41781506 0.5391019 0.99052346
		 0.98492682 0.41781506 0.98492682 0.99052346 0.5391019 0.71306276 0.5391019 0.99052346
		 0.98492682 0.71306276 0.98492682 0.99052346 0.007258594 0.50389278 0.007258594 0.99274147
		 0.3878029 0.50389278 0.3878029 0.99274147 0.007258594 0.75590837 0.007258594 0.8140775;
	setAttr ".uvst[0].uvsp[500:539]" 0.3878029 0.75590837 0.3878029 0.8140775 0.007258594
		 0.99274147 0.3878029 0.99274147 0.007258594 0.50389278 0.007258594 0.99274147 0.49610728
		 0.50389278 0.49610728 0.99274147 0.5391019 0.41781506 0.98492682 0.41781506 0.5391019
		 0.99052346 0.98492682 0.99052346 0.53738743 0.71306276 0.98321241 0.71306276 0.53738743
		 0.99052346 0.98321241 0.99052346 0.007258594 0.50389278 0.3878029 0.50389278 0.007258594
		 0.99274147 0.3878029 0.99274147 0.007258594 0.75590837 0.3878029 0.75590837 0.007258594
		 0.8140775 0.3878029 0.8140775 0.007258594 0.99274147 0.3878029 0.99274147 0.007258594
		 0.50389278 0.49610728 0.50389278 0.007258594 0.99274147 0.49610728 0.99274147 0.007258594
		 0.50389278 0.007258594 0.99274147 0.3878029 0.50389278 0.3878029 0.99274147 0.007258594
		 0.75590837 0.007258594 0.8140775 0.3878029 0.75590837 0.3878029 0.8140775 0.007258594
		 0.99274147 0.3878029 0.99274147;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 460 ".vt";
	setAttr ".vt[0:165]"  -6.99572182 -0.0087249996 12.030825615 8.0040073395 -0.0087249996 12.030825615
		 -6.99572182 -0.0087249996 -12 8.0040073395 -0.0087249996 -12 -1.045281053 -0.0087249996 -10.0053119659
		 -1.045281053 1 -10.0053119659 -1.045281053 -0.0087249996 -12.038850784 -1.045281053 1 -12.038850784
		 -1.038401008 -0.0087249996 -12 -1.038401008 1 -12 -6.99572182 -0.0087249996 -12 -6.99572182 1 -12
		 -2.062674999 -0.0087249996 -10.96281528 -2.062674999 1 -10.96281528 -5.88953686 -0.0087249996 -10.96281528
		 -5.88953686 1 -10.96281528 -1.029296994 -0.0087249996 -10.0053119659 -1.029296994 1 -10.0053119659
		 -4.94581223 -0.0087249996 -10.0053119659 -4.94581223 1 -10.0053119659 0.010738 -0.0087249996 -6.010855198
		 0.010738 1 -6.010855198 0.010738 -0.0087249996 -12.024394989 0.010738 1 -12.024394989
		 3.0011949539 -0.0087249996 -7.01259613 3.0011949539 1 -7.01259613 0.960697 -0.0087249996 -7.012597084
		 0.960697 1 -7.012597084 8.0040073395 -0.0087249996 -11.99918747 8.0040073395 1 -11.99918747
		 0.0040509999 -0.0087249996 -11.99918747 0.0040509999 1 -11.99918747 7.014523983 -0.0087249996 -11.038878441
		 7.014523983 1 -11.038878441 0.960697 -0.0087249996 -11.038878441 0.960697 1 -11.038878441
		 5.99549103 -0.0087249996 -9.99749947 5.99549103 1 -9.99749947 0.030174 -0.0087249996 -9.99749947
		 0.030174 1 -9.99749947 4.99825907 -0.0087249996 -9.015663147 4.99825907 1 -9.015663147
		 0.960697 -0.0087249996 -9.015663147 0.960697 1 -9.015663147 4.0042538643 -0.0087249996 -8.012235641
		 4.0042538643 1 -8.012235641 0.030174 -0.0087249996 -8.012235641 0.030174 1 -8.012235641
		 8.0023088455 -0.0087249996 -5.00098323822 8.0023088455 1 -5.00098323822 8.0059309006 -0.0087249996 -11.9952507
		 8.0059309006 1 -11.9952507 7.011658192 -0.0087249996 -5.020114899 7.011658192 1 -5.020114899
		 7.011658192 -0.0087249996 -11.041661263 7.011658192 1 -11.041661263 6.013024807 -0.0087249996 -5
		 6.013024807 1 -5 6.013024807 -0.0087249996 -9.99409103 6.013024807 1 -9.99409103
		 5.0069479942 -0.0087249996 -5 5.0069479942 1 -5 5.0069479942 -0.0087249996 -9.029397964
		 5.0069479942 1 -9.029397964 -1.010033011 -0.0087249996 -5 -1.010033011 1 -5 -1.010033011 -0.0087249996 -7.99611187
		 -1.010033011 1 -7.99611187 0.001956 -0.0087249996 -9.015663147 0.001956 1 -9.015663147
		 -4.035604954 -0.0087249996 -9.015663147 -4.035604954 1 -9.015663147 -1.010033011 -0.0087249996 -8.009437561
		 -1.010033011 1 -8.009437561 -2.98378491 -0.0087249996 -8.009437561 -2.98378491 1 -8.009437561
		 3.99171901 -0.0087249996 -5 3.99171901 1 -5 3.99171901 -0.0087249996 -7.99611187
		 3.99171901 1 -7.99611187 -2.98378491 -0.0087249996 -5 -2.98378491 1 -5 -2.98378491 -0.0087249996 -7.99611187
		 -2.98378491 1 -7.99611187 -4.035604954 -0.0087249996 -5 -4.035604954 1 -5 -4.035604954 -0.0087249996 -9.029397964
		 -4.035604954 1 -9.029397964 -4.9090209 -0.0087249996 -5 -4.9090209 1 -5 -4.94581223 -0.0087249996 -9.99409103
		 -4.94581223 1 -9.99409103 -5.98818111 -0.0087249996 -5 -5.98818111 1 -5 -5.88953686 -0.0087249996 -10.96281528
		 -5.88953686 1 -10.96281528 -6.99572182 -0.0087249996 -5 -6.99572182 1 -5 -6.99572182 -0.0087249996 -11.9952507
		 -6.99572182 1 -11.9952507 -2 -0.0087249996 -5 -2 1 -5 -2 -0.0087249996 -7 -2 1 -7
		 1 -0.0087249996 -5.98170996 1 1 -5.98170996 1 -0.0087249996 -7 1 1 -7 3 -0.0087249996 -5
		 3 1 -5 3 -0.0087249996 -7 3 1 -7 2 -0.0087249996 -5 2 1 -5 2 -0.0087249996 -6 2 1 -6
		 1.009526968 -0.0087249996 -5.28838587 1.009526968 1 -5.28838587 0.0095269997 -0.0087249996 -5.28838587
		 0.0095269997 1 -5.28838587 0 -0.0087249996 -6.011088848 0 1 -6.011088848 1 -0.0087249996 -6.011088848
		 1 1 -6.011088848 0.49399799 1 -4.99897003 0.49399799 -0.0087249996 -4.99897003 1.39114594 -0.0087249996 -4.28446102
		 1.39114594 1 -4.28446102 -0.37209201 -0.0087249996 -4.28446102 -0.37209201 1 -4.28446102
		 -0.98223799 -0.0087249996 -5.0071640015 -0.98223799 1 -5.0071640015 1.98223805 -0.0087249996 -5.0071640015
		 1.98223805 1 -5.0071640015 0.49399799 1 -3.99504495 0.49399799 -0.0087249996 -3.99504495
		 2.19838309 -0.0087249996 -3.73310995 2.19838309 1 -3.73310995 -1.17932904 -0.0087249996 -3.73310995
		 -1.17932904 1 -3.73310995 -2 -0.0087249996 -5 -2 1 -5 2.983675 -0.0087249996 -5 2.983675 1 -5
		 0.49399799 1 -3.0021240711 0.49399799 -0.0087249996 -3.0021240711 2.98664093 -0.0087249996 -3.064126968
		 2.98664093 1 -3.064126968 -1.96758699 -0.0087249996 -3.064126968 -1.96758699 1 -3.064126968
		 -3.029901028 -0.0087249996 -5 -3.029901028 1 -5 4.013576031 -0.0087249996 -5 4.013576031 1 -5
		 0.49399799 1 -1.98347402 0.49399799 -0.0087249996 -1.98347402 3.52245688 -0.0087249996 -2.47116303
		 3.52245593 1 -2.47116303 4.9905262 -0.0087249996 -5 4.9905262 1 -5 3 1 -1.71481395
		 3 -0.0087249996 -1.71481395 -2.98008299 -0.0087249996 -2.62439609 -2.98008299 1 -2.62439609
		 -4.00685215 -0.0087249996 -5 -4.00685215 1 -5;
	setAttr ".vt[166:331]" -2 -0.0087249996 -1.71481395 -2 1 -1.71481395 2.055490017 -0.0087249996 10.011742592
		 2.055490017 1 10.011742592 2.055490017 -0.0087249996 12.04528141 2.055490017 1 12.04528141
		 2.048609972 -0.0087249996 12.0064306259 2.048609972 1 12.0064306259 8.0059309006 -0.0087249996 12.0064306259
		 8.0059309006 1 12.0064306259 3.072884083 -0.0087249996 10.96924591 3.072884083 1 10.96924591
		 6.89974594 -0.0087249996 10.96924591 6.89974594 1 10.96924591 2.039505959 -0.0087249996 10.011742592
		 2.039505959 1 10.011742592 5.95602083 -0.0087249996 10.011742592 5.95602083 1 10.011742592
		 0.99947101 -0.0087249996 6.01728487 0.99947101 1 6.01728487 0.99947101 -0.0087249996 12.030825615
		 0.99947101 1 12.030825615 -1.99098599 -0.0087249996 7.019025803 -1.99098599 1 7.019025803
		 0.049511999 -0.0087249996 7.019027233 0.049511999 1 7.019027233 -6.99379778 -0.0087249996 12.0056171417
		 -6.99379778 1 12.0056171417 1.0061579943 -0.0087249996 12.0056171417 1.0061579943 1 12.0056171417
		 -6.0043148994 -0.0087249996 11.045309067 -6.0043148994 1 11.045309067 0.049511999 -0.0087249996 11.045309067
		 0.049511999 1 11.045309067 -4.98528194 -0.0087249996 10.0039300919 -4.98528194 1 10.0039300919
		 -1 -0.0087249996 10.0039300919 -1 1 10.0039300919 -3.98804998 -0.0087249996 9.022093773
		 -3.98804998 1 9.022093773 0.049511999 -0.0087249996 9.022093773 0.049511999 1 9.022093773
		 0.049511999 -0.0087249996 11.045309067 0.049511999 1 11.045309067 -2.99404502 -0.0087249996 8.018666267
		 -2.99404502 1 8.018666267 0.98003501 -0.0087249996 8.018666267 0.98003501 1 8.018666267
		 -6.99572182 -0.0087249996 5 -6.99572182 1 5 -6.99572182 -0.0087249996 12.0016813278
		 -6.99572182 1 12.0016813278 -6.0014491081 -0.0087249996 5 -6.0014491081 1 5 -6.0014491081 -0.0087249996 11.048091888
		 -6.0014491081 1 11.048091888 -5.0028162003 -0.0087249996 5 -5.0028162003 1 5 -5.0028162003 -0.0087249996 10.00052165985
		 -5.0028162003 1 10.00052165985 -3.99673891 -0.0087249996 5.0064301491 -3.99673891 1 5.0064301491
		 -3.99673891 -0.0087249996 9.03582859 -3.99673891 1 9.03582859 2.020241976 -0.0087249996 5.0064301491
		 2.020241976 1 5.0064301491 2.020241976 -0.0087249996 8.0025415421 2.020241976 1 8.0025415421
		 1.0082529783 -0.0087249996 9.022093773 1.0082529783 1 9.022093773 5.045814991 -0.0087249996 9.022093773
		 5.045814991 1 9.022093773 2.020241976 -0.0087249996 8.015868187 2.020241976 1 8.015868187
		 3.993994 -0.0087249996 8.015868187 3.993994 1 8.015868187 -2.98150992 -0.0087249996 5.0064301491
		 -2.98150992 1 5.0064301491 -2.98150992 -0.0087249996 8.0025415421 -2.98150992 1 8.0025415421
		 3.993994 -0.0087249996 5.0064301491 3.993994 1 5.0064301491 3.993994 -0.0087249996 8.0025415421
		 3.993994 1 8.0025415421 5.045814991 -0.0087249996 5.0064301491 5.045814991 1 5.0064301491
		 5.045814991 -0.0087249996 9.03582859 5.045814991 1 9.03582859 6 -0.0087249996 5 6 1 5
		 5.95602083 -0.0087249996 10.00052165985 5.95602083 1 10.00052165985 7 -0.0087249996 5
		 7 1 5 6.89974594 -0.0087249996 10.96924591 6.89974594 1 10.96924591 8.0059309006 -0.0087249996 5
		 8.0059309006 1 5 8.0059309006 -0.0087249996 12.0016813278 8.0059309006 1 12.0016813278
		 3.010209084 -0.0087249996 5.0064301491 3.010209084 1 5.0064301491 3.010209084 -0.0087249996 7.0064301491
		 3.010209084 1 7.0064301491 0.010209 -0.0087249996 5.98814011 0.010209 1 5.98814011
		 0.010209 -0.0087249996 7.0064301491 0.010209 1 7.0064301491 -1.98979104 -0.0087249996 5.0064301491
		 -1.98979104 1 5.0064301491 -1.98979104 -0.0087249996 7.0064301491 -1.98979104 1 7.0064301491
		 -0.98979098 -0.0087249996 5.0064301491 -0.98979098 1 5.0064301491 -0.98979098 -0.0087249996 6.0064301491
		 -0.98979098 1 6.0064301491 0.00068200001 -0.0087249996 5.29481602 0.00068200001 1 5.29481602
		 1.00068199635 -0.0087249996 5.29481602 1.00068199635 1 5.29481602 1.010208964 -0.0087249996 6.017518997
		 1.010208964 1 6.017518997 0.010209 -0.0087249996 6.017518997 0.010209 1 6.017518997
		 0.51621097 1 5.0054001808 0.51621097 -0.0087249996 5.0054001808 -0.38093701 -0.0087249996 4.29089117
		 -0.38093701 1 4.29089117 1.38230097 -0.0087249996 4.29089117 1.38230097 1 4.29089117
		 1.99244702 -0.0087249996 5.013594151 1.99244702 1 5.013594151 -0.97202897 -0.0087249996 5.013594151
		 -0.97202897 1 5.013594151 0.51621097 1 4.0014748573 0.51621097 -0.0087249996 4.0014748573
		 -1.18817401 -0.0087249996 3.73954105 -1.18817401 1 3.73954105 2.189538 -0.0087249996 3.73954105
		 2.189538 1 3.73954105 3.010209084 -0.0087249996 5.0064301491 3.010209084 1 5.0064301491
		 -1.97346604 -0.0087249996 5.0064301491 -1.97346604 1 5.0064301491 0.51621097 1 3.0085539818
		 0.51621097 -0.0087249996 3.0085539818 -1.97643197 -0.0087249996 3.070557117 -1.97643197 1 3.070557117
		 2.97779703 -0.0087249996 3.070557117 2.97779703 1 3.070557117 4.040110111 -0.0087249996 5.0064301491
		 4.040110111 1 5.0064301491 -3.0033659935 -0.0087249996 5.0064301491 -3.0033659935 1 5.0064301491
		 0.51621097 1 1.989905 0.51621097 -0.0087249996 1.989905 -3.41580606 -0.0087249996 2.98123598
		 -3.41580606 1 2.98123598 -3.98031712 -0.0087249996 5.0064311028 -3.98031712 1 5.0064311028
		 -1.73580599 1 1.29056501 -1.73580599 -0.0087249996 1.29056501 -2.90136099 1 2.19913697
		 -2.90136099 -0.0087249996 2.19913697 3.61876798 -0.0087249996 2.42018294 3.61876798 1 2.42018294;
	setAttr ".vt[332:459]" 5.017061234 -0.0087249996 5.0064311028 5.017061234 1 5.0064311028
		 1.50638998 -0.0087249996 1 1.50639105 1 1 -6.54970884 -0.0087249996 -2.41375303 -6.54970884 1 -2.41375303
		 -6.99242783 -0.0087249996 -5 -6.99242783 1 -5 -5 -0.0087249996 0 -5 1 0 -5.54546309 -0.0087249996 -2.41375303
		 -5.54546309 1 -2.41375303 -5.98818111 -0.0087249996 -5 -5.98818111 1 -5 -3.995754 -0.0087249996 0
		 -3.995754 1 0 -4.46630287 -0.0087249996 -3.10644603 -4.46630287 1 -3.10644603 -4.9090209 -0.0087249996 -5
		 -4.9090209 1 -5 -3.24696803 -0.0087249996 -1.10893703 -3.24696803 1 -1.10893703 -4.55549002 -0.0087249996 2.41353607
		 -4.55549002 1 2.41353607 -4.99820805 -0.0087249996 4.99978399 -4.99820805 1 4.99978399
		 -2 -0.0087249996 0 -2 1 0 -3.53337312 1 0.85300499 -3.53337312 -0.0087249996 0.85300499
		 0.52847898 -0.0087249996 0.998285 0.52847898 1 0.998285 0.52847898 -0.0087249996 2
		 0.52847898 1 2 -2 -0.0087249996 0 -2 1 0 0.52847898 -0.0087249996 0.98298502 0.52847898 1 0.98298502
		 -1.17669296 1 0.60711098 -1.17669296 -0.0087249996 0.60711098 -0.32503799 1 0.94809598
		 -0.32503799 -0.0087249996 0.94809598 5.0372262 -0.0087249996 2.42018294 5.0372262 1 2.42018294
		 6 -0.0087249996 5 6 1 5 4 -0.0087249996 1 4 1 1 7.55811214 -0.0087249996 -2.41375303
		 7.55811214 1 -2.41375303 8.00082969666 -0.0087249996 -5 8.00082969666 1 -5 6.0084018707 -0.0087249996 0
		 6.0084018707 1 0 5.55691195 -0.0087249996 -3.074821949 5.55691195 1 -3.074821949
		 5.99962997 -0.0087249996 -5 5.99962997 1 -5 4.34963799 -0.0087249996 -1.44622195
		 4.34963799 1 -1.44622195 -2 -0.0087249996 -1.0046490431 -2 1 -1.0046490431 0.52847898 -0.0087249996 -0.021663999
		 0.52847898 1 -0.021663999 -1.17669296 1 -0.39753801 -1.17669296 -0.0087249996 -0.39753801
		 -0.32503799 1 -0.056552 -0.32503799 -0.0087249996 -0.056552 1.31173098 -0.0087249996 -0.122406
		 1.31173098 1 -0.122406 2.056030035 -0.0087249996 -0.41247499 2.056030035 1 -0.41247499
		 2.99658394 -0.0087249996 -1 2.99658394 1 -1 0.52847898 -0.0087249996 -1.026389956
		 0.52847898 1 -1.026389956 0.52847898 -0.0087249996 -0.024675 0.52847898 1 -0.024675
		 -0.241144 -0.0087249996 -1.69688404 -0.241144 1 -1.69688404 1.24250805 -0.0087249996 -1.69688404
		 1.24250805 1 -1.69688404 1.82253301 -0.0087249996 -0.974181 1.82253301 1 -0.974181
		 -0.80211502 -0.0087249996 -0.974181 -0.80211502 1 -0.974181 0.51621097 1 -1.98629999
		 0.51621097 -0.0087249996 -1.98629999 -6.54970884 -0.0087249996 2.42179608 -6.54970884 1 2.42179608
		 -6.99242783 -0.0087249996 5.008043766 -6.99242783 1 5.008043766 -5 -0.0087249996 0.0080429995
		 -5 1 0.0080429995 -5.54546309 -0.0087249996 2.41353607 -5.54546309 1 2.41353607 -5.98818111 -0.0087249996 4.99978399
		 -5.98818111 1 4.99978399 -2 -0.0087249996 -1 -2 1 -1 -4 1 0 -4 -0.0087249996 0 -2 1 -1.71481395
		 -2 -0.0087249996 -1.71481395 7.54629278 -0.0087249996 2.42179608 7.54629278 1 2.42179608
		 7.98901176 -0.0087249996 5.008043766 7.98901176 1 5.008043766 5.99658394 -0.0087249996 0.0080429995
		 5.99658394 1 0.0080429995 6.54204702 -0.0087249996 2.41353607 6.54204702 1 2.41353607
		 6.98476505 -0.0087249996 4.99978399 6.98476505 1 4.99978399 2.99658394 -0.0087249996 -1
		 2.99658394 1 -1 4.99658394 1 0 4.99658394 -0.0087249996 0 2.99658394 1 -1.71481395
		 2.99658394 -0.0087249996 -1.71481395 6.54204702 -0.0087249996 -2.43386698 6.54204702 1 -2.43386698
		 6.98476505 -0.0087249996 -5.020114899 6.98476505 1 -5.020114899 1.50638998 -0.0087249996 0.97966802
		 1.50639105 1 0.97966802 4.12928104 1 -0.020331001 4.12928104 -0.0087249996 -0.020331001;
	setAttr -s 662 ".ed";
	setAttr ".ed[0:165]"  0 1 0 1 2 0 2 0 0 1 3 0 3 2 0 4 5 0 5 6 0 6 4 0 5 7 0
		 7 6 0 8 9 0 9 10 0 10 8 0 9 11 0 11 10 0 12 13 0 13 14 0 14 12 0 13 15 0 15 14 0
		 16 17 0 17 18 0 18 16 0 17 19 0 19 18 0 20 21 0 21 22 0 22 20 0 21 23 0 23 22 0 24 25 0
		 25 26 0 26 24 0 25 27 0 27 26 0 28 29 0 29 30 0 30 28 0 29 31 0 31 30 0 32 33 0 33 34 0
		 34 32 0 33 35 0 35 34 0 36 37 0 37 38 0 38 36 0 37 39 0 39 38 0 40 41 0 41 42 0 42 40 0
		 41 43 0 43 42 0 44 45 0 45 46 0 46 44 0 45 47 0 47 46 0 48 49 0 49 50 0 50 48 0 49 51 0
		 51 50 0 52 53 0 53 54 0 54 52 0 53 55 0 55 54 0 56 57 0 57 58 0 58 56 0 57 59 0 59 58 0
		 60 61 0 61 62 0 62 60 0 61 63 0 63 62 0 64 65 0 65 66 0 66 64 0 65 67 0 67 66 0 68 69 0
		 69 70 0 70 68 0 69 71 0 71 70 0 72 73 0 73 74 0 74 72 0 73 75 0 75 74 0 76 77 0 77 78 0
		 78 76 0 77 79 0 79 78 0 80 81 0 81 82 0 82 80 0 81 83 0 83 82 0 84 85 0 85 86 0 86 84 0
		 85 87 0 87 86 0 88 89 0 89 90 0 90 88 0 89 91 0 91 90 0 92 93 0 93 94 0 94 92 0 93 95 0
		 95 94 0 96 97 0 97 98 0 98 96 0 97 99 0 99 98 0 100 101 0 101 102 0 102 100 0 101 103 0
		 103 102 0 104 105 0 105 106 0 106 104 0 105 107 0 107 106 0 108 109 0 109 110 0 110 108 0
		 109 111 0 111 110 0 112 113 0 113 114 0 114 112 0 113 115 0 115 114 0 116 117 0 117 125 0
		 125 116 0 117 124 0 124 125 0 118 119 0 119 120 0 120 118 0 119 121 0 121 120 0 117 122 0
		 122 116 0 117 123 0 123 122 0 124 118 0 118 125 0 124 119 0 126 127 0 127 135 0 135 126 0
		 127 134 0;
	setAttr ".ed[166:331]" 134 135 0 128 129 0 129 130 0 130 128 0 129 131 0 131 130 0
		 127 132 0 132 126 0 127 133 0 133 132 0 134 128 0 128 135 0 134 129 0 136 137 0 137 145 0
		 145 136 0 137 144 0 144 145 0 138 139 0 139 140 0 140 138 0 139 141 0 141 140 0 137 142 0
		 142 136 0 137 143 0 143 142 0 144 138 0 138 145 0 144 139 0 146 147 0 147 155 0 155 146 0
		 147 154 0 154 155 0 148 149 0 149 150 0 150 148 0 149 151 0 151 150 0 147 152 0 152 146 0
		 147 153 0 153 152 0 154 148 0 148 155 0 154 149 0 156 157 0 157 161 0 161 156 0 157 160 0
		 160 161 0 157 158 0 158 156 0 157 159 0 159 158 0 162 163 0 163 164 0 164 162 0 163 165 0
		 165 164 0 166 167 0 167 162 0 162 166 0 167 163 0 168 169 0 169 170 0 170 168 0 169 171 0
		 171 170 0 172 173 0 173 174 0 174 172 0 173 175 0 175 174 0 176 177 0 177 178 0 178 176 0
		 177 179 0 179 178 0 180 181 0 181 182 0 182 180 0 181 183 0 183 182 0 184 185 0 185 186 0
		 186 184 0 185 187 0 187 186 0 188 189 0 189 190 0 190 188 0 189 191 0 191 190 0 192 193 0
		 193 194 0 194 192 0 193 195 0 195 194 0 196 197 0 197 198 0 198 196 0 197 199 0 199 198 0
		 200 201 0 201 202 0 202 200 0 201 203 0 203 202 0 204 205 0 205 206 0 206 204 0 205 207 0
		 207 206 0 207 208 0 208 206 0 207 209 0 209 208 0 210 211 0 211 212 0 212 210 0 211 213 0
		 213 212 0 214 215 0 215 216 0 216 214 0 215 217 0 217 216 0 218 219 0 219 220 0 220 218 0
		 219 221 0 221 220 0 222 223 0 223 224 0 224 222 0 223 225 0 225 224 0 226 227 0 227 228 0
		 228 226 0 227 229 0 229 228 0 230 231 0 231 232 0 232 230 0 231 233 0 233 232 0 234 235 0
		 235 236 0 236 234 0 235 237 0 237 236 0 238 239 0 239 240 0 240 238 0 239 241 0 241 240 0
		 242 243 0 243 244 0 244 242 0 243 245 0 245 244 0 246 247 0 247 248 0;
	setAttr ".ed[332:497]" 248 246 0 247 249 0 249 248 0 250 251 0 251 252 0 252 250 0
		 251 253 0 253 252 0 254 255 0 255 256 0 256 254 0 255 257 0 257 256 0 258 259 0 259 260 0
		 260 258 0 259 261 0 261 260 0 262 263 0 263 264 0 264 262 0 263 265 0 265 264 0 266 267 0
		 267 268 0 268 266 0 267 269 0 269 268 0 270 271 0 271 272 0 272 270 0 271 273 0 273 272 0
		 274 275 0 275 276 0 276 274 0 275 277 0 277 276 0 278 279 0 279 280 0 280 278 0 279 281 0
		 281 280 0 282 283 0 283 291 0 291 282 0 283 290 0 290 291 0 284 285 0 285 286 0 286 284 0
		 285 287 0 287 286 0 283 288 0 288 282 0 283 289 0 289 288 0 290 284 0 284 291 0 290 285 0
		 292 293 0 293 301 0 301 292 0 293 300 0 300 301 0 294 295 0 295 296 0 296 294 0 295 297 0
		 297 296 0 293 298 0 298 292 0 293 299 0 299 298 0 300 294 0 294 301 0 300 295 0 302 303 0
		 303 311 0 311 302 0 303 310 0 310 311 0 304 305 0 305 306 0 306 304 0 305 307 0 307 306 0
		 303 308 0 308 302 0 303 309 0 309 308 0 310 304 0 304 311 0 310 305 0 312 313 0 313 321 0
		 321 312 0 313 320 0 320 321 0 314 315 0 315 316 0 316 314 0 315 317 0 317 316 0 313 318 0
		 318 312 0 313 319 0 319 318 0 320 314 0 314 321 0 320 315 0 322 323 0 323 329 0 329 322 0
		 323 328 0 328 329 0 323 324 0 324 322 0 323 325 0 325 324 0 328 327 0 327 329 0 328 326 0
		 326 327 0 330 331 0 331 332 0 332 330 0 331 333 0 333 332 0 334 335 0 335 330 0 330 334 0
		 335 331 0 336 337 0 337 338 0 338 336 0 337 339 0 339 338 0 340 341 0 341 336 0 336 340 0
		 341 337 0 342 343 0 343 344 0 344 342 0 343 345 0 345 344 0 346 347 0 347 342 0 342 346 0
		 347 343 0 348 349 0 349 350 0 350 348 0 349 351 0 351 350 0 352 353 0 353 348 0 348 352 0
		 353 349 0 354 356 0 356 355 0 355 354 0 356 357 0 357 355 0 358 361 0;
	setAttr ".ed[498:661]" 361 359 0 359 358 0 361 360 0 360 359 0 361 354 0 354 360 0
		 355 360 0 362 363 0 363 364 0 364 362 0 363 365 0 365 364 0 366 367 0 367 371 0 371 366 0
		 367 370 0 370 371 0 370 373 0 373 371 0 370 372 0 372 373 0 372 368 0 368 373 0 372 369 0
		 369 368 0 374 375 0 375 376 0 376 374 0 375 377 0 377 376 0 378 379 0 379 374 0 374 378 0
		 379 375 0 380 382 0 382 381 0 381 380 0 382 383 0 383 381 0 384 380 0 380 385 0 385 384 0
		 381 385 0 386 388 0 388 387 0 387 386 0 388 389 0 389 387 0 390 386 0 386 391 0 391 390 0
		 387 391 0 392 393 0 393 397 0 397 392 0 393 396 0 396 397 0 396 399 0 399 397 0 396 398 0
		 398 399 0 398 394 0 394 399 0 398 395 0 395 394 0 395 400 0 400 394 0 395 401 0 401 400 0
		 401 402 0 402 400 0 401 403 0 403 402 0 403 404 0 404 402 0 403 405 0 405 404 0 406 407 0
		 407 408 0 408 406 0 407 409 0 409 408 0 410 411 0 411 419 0 419 410 0 411 418 0 418 419 0
		 412 413 0 413 414 0 414 412 0 413 415 0 415 414 0 411 416 0 416 410 0 411 417 0 417 416 0
		 418 412 0 412 419 0 418 413 0 420 422 0 422 421 0 421 420 0 422 423 0 423 421 0 424 420 0
		 420 425 0 425 424 0 421 425 0 426 428 0 428 427 0 427 426 0 428 429 0 429 427 0 430 433 0
		 433 431 0 431 430 0 433 432 0 432 431 0 433 426 0 426 432 0 427 432 0 431 434 0 434 430 0
		 434 435 0 435 430 0 436 437 0 437 438 0 438 436 0 437 439 0 439 438 0 440 441 0 441 436 0
		 436 440 0 441 437 0 442 443 0 443 444 0 444 442 0 443 445 0 445 444 0 446 447 0 447 449 0
		 449 446 0 447 448 0 448 449 0 448 442 0 442 449 0 448 443 0 446 450 0 450 447 0 446 451 0
		 451 450 0 452 454 0 454 453 0 453 452 0 454 455 0 455 453 0 456 459 0 459 457 0 457 456 0
		 459 458 0 458 457 0 459 452 0 452 458 0 453 458 0;
	setAttr -s 864 ".n";
	setAttr ".n[0:165]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0
		 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 -1
		 0 -0.00051799999 -1 0 -0.00051799999 -1 0 -0.00051799999 -1 0 -0.00051799999 -1 0
		 -0.00051799999 -1 0 -0.00051799999 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0
		 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -0.999973
		 0 0.007367 -0.999973 0 0.007367 -0.999973 0 0.007367 -0.999973 0 0.007367 -0.999973
		 0 0.007367 -0.999973 0 0.007367 -0.99986303 0 -0.016541 -0.99986303 0 -0.016541 -0.99986303
		 0 -0.016541 -0.99986303 0 -0.016541 -0.99986303 0 -0.016541 -0.99986303 0 -0.016541
		 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0
		 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
	setAttr ".n[166:331]" -type "float3"  -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 0.48953101 0 0.87198597 0.48953101 0 0.87198597 0.176338 0 0.98433
		 0.176338 0 0.98433 0.48953101 0 0.87198597 -0.202792 0 0.979222 -0.99991298 0 0.013182
		 -0.99991298 0 0.013181 -0.99991298 0 0.013181 -0.99991298 0 0.013181 -0.99991298
		 0 0.013181 -0.99991298 0 0.013181 -0.99991298 0 0.013181 -0.99991298 0 0.013181 -0.99991298
		 0 0.013181 -0.99991298 0 0.013181 -0.99991298 0 0.013181 -0.99991298 0 0.013181 0.176338
		 0 0.98433 -0.202792 0 0.979222 -0.51284403 0 0.858482 -0.51284403 0 0.858482 -0.202792
		 0 0.979222 -0.51284498 0 0.85848099 0.30701599 0 0.95170403 0.30701599 0 0.95170403
		 0.103616 0 0.99461699 0.103616 0 0.99461699 0.30701599 0 0.95170403 -0.113995 0 0.99348098
		 -0.76410103 0 0.64509702 -0.76410103 0 0.64509702 -0.76410103 0 0.64509702 -0.76410103
		 0 0.64509702 -0.76410103 0 0.64509702 -0.76410198 0 0.645096 -0.77406698 0 -0.63310301
		 -0.774068 0 -0.63310301 -0.774068 0 -0.63310301 -0.774068 0 -0.63310301 -0.774068
		 0 -0.63310301 -0.774068 0 -0.63310301 0.103616 0 0.99461699 -0.113995 0 0.99348098
		 -0.316937 0 0.94844699 -0.316937 0 0.94844699 -0.113995 0 0.99348098 -0.316937 0
		 0.94844699 0.39416301 0 0.91904002 0.39416301 0 0.91904002 0.139489 0 0.990224 0.139489
		 0 0.990224 0.39416301 0 0.91904002 -0.146125 0 0.98926598 -0.839293 0 0.54368001
		 -0.839293 0 0.54368001 -0.839293 0 0.54368001 -0.839293 0 0.54368001 -0.839293 0
		 0.54368001 -0.83929199 0 0.54368001 -0.84995699 -1e-006 -0.52685201 -0.84995699 0
		 -0.52685201 -0.84995699 0 -0.52685201 -0.84995699 0 -0.52685201 -0.84995699 0 -0.52685201
		 -0.84995699 0 -0.52685302 0.139489 0 0.990224 -0.146125 0 0.98926598 -0.400316 0
		 0.91637701 -0.400316 0 0.91637701 -0.146125 0 0.98926598 -0.400316 0 0.91637701 0.39776501
		 0 0.91748798 0.39776501 0 0.91748798 0.141635 0 0.98991901 0.141635 0 0.98991901
		 0.39776501 0 0.91748798 -0.146183 0 0.98925799 -0.87667799 0 0.481078 -0.87667799
		 0 0.481078 -0.87667799 0 0.481078 -0.87667799 0 0.481078 -0.87667799 0 0.481078 -0.87667799
		 0 0.481078 -0.88339901 0 -0.468622 -0.88339901 0 -0.468622 -0.88339901 0 -0.468622
		 -0.88339901 0 -0.468622 -0.88339901 0 -0.468622 -0.88339901 0 -0.468622 0.141635
		 0 0.98991901 -0.146183 0 0.98925799 -0.40197599 0 0.91565001 -0.40197599 0 0.91565001
		 -0.146183 0 0.98925799 -0.40197599 0 0.91565001 0.82278699 1e-006 0.56835002 0.82278699
		 0 0.56835002 0.82278699 0 0.56835002 0.82278699 0 0.56835002 0.82278699 0 0.56835002
		 0.82278699 0 0.568349 -0.86483198 -1e-006 -0.50206202 -0.86483198 0 -0.50206202 -0.86483198
		 0 -0.50206202 -0.86483198 0 -0.50206202 -0.86483198 0 -0.50206202 -0.86483198 0 -0.50206202
		 -0.91793001 0 0.39674199 -0.91793001 0 0.39674199 -0.91793001 0 0.39674199 -0.91793001
		 0 0.39674199 -0.91793001 0 0.39674199 -0.91793001 0 0.39674199 -0.68025202 0 0.73297799
		 -0.68025202 0 0.73297799 -0.68025202 0 0.73297799 -0.68025202 0 0.73297799 -0.68025202
		 0 0.73297799 -0.68025202 0 0.73297799 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0
		 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1;
	setAttr ".n[332:497]" -type "float3"  0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0
		 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0 -1 0 0
		 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0
		 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0.99996102
		 0 0.0087940004 0.99996102 0 0.0087940004 0.99996102 0 0.0087940004 0.99996102 0 0.0087940004
		 0.99996102 0 0.0087940004 0.99996102 0 0.0087940004 0.99985898 0 0.016793 0.99985898
		 0 0.016793 0.99985898 0 0.016793 0.99985898 0 0.016793 0.99985898 0 0.016793 0.99985898
		 0 0.016793 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0
		 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 1 0 0 1 0 0 1 0 0 -0.48953 0 -0.87198699 -0.48953 0 -0.87198597 -0.176337
		 0 -0.98433 -0.176337 0 -0.98433 -0.48953 0 -0.87198597 0.20279101 0 -0.979222 0.99991298
		 0 -0.013182 0.99991298 0 -0.013181 0.99991298 0 -0.013181 0.99991298 0 -0.013181
		 0.99991298 0 -0.013181 0.99991298 0 -0.013181 0.99991298 0 -0.013181 0.99991298 0
		 -0.013181 0.99991298 0 -0.013181 0.99991298 0 -0.013181 0.99991298 0 -0.013181 0.99991298
		 0 -0.013181 -0.176337 0 -0.98433 0.20279101 0 -0.979222 0.51284403 0 -0.858482 0.51284403
		 0 -0.858482 0.20279101 0 -0.979222 0.51284301 0 -0.85848302 -0.30701599 0 -0.95170498
		 -0.30701599 0 -0.95170403 -0.103615 0 -0.99461699 -0.103615 0 -0.99461699 -0.30701599
		 0 -0.95170403 0.113995 0 -0.99348098;
	setAttr ".n[498:663]" -type "float3"  0.76410103 0 -0.645096 0.76410103 0 -0.645096
		 0.76410103 0 -0.645096 0.76410103 0 -0.645096 0.76410103 0 -0.645096 0.76410103 0
		 -0.64509702 0.774068 0 0.63310301 0.774068 0 0.63310301 0.774068 0 0.63310301 0.774068
		 0 0.63310301 0.774068 0 0.63310301 0.774068 0 0.63310301 -0.103615 0 -0.99461699
		 0.113995 0 -0.99348098 0.31693599 0 -0.94844699 0.31693599 0 -0.94844699 0.113995
		 0 -0.99348098 0.316935 0 -0.94844699 -0.39416301 0 -0.91904002 -0.394164 0 -0.91904002
		 -0.139489 0 -0.990224 -0.139489 0 -0.990224 -0.394164 0 -0.91904002 0.146125 0 -0.98926598
		 0.83929199 0 -0.54368001 0.83929199 0 -0.54368001 0.83929199 0 -0.54368001 0.83929199
		 0 -0.54368001 0.83929199 0 -0.54368001 0.83929199 0 -0.54368001 0.84995699 0 0.52685201
		 0.84995699 0 0.52685302 0.84995699 0 0.52685302 0.84995699 0 0.52685302 0.84995699
		 0 0.52685302 0.84995699 0 0.52685302 -0.139489 0 -0.990224 0.146125 0 -0.98926598
		 0.400316 0 -0.91637701 0.400316 0 -0.91637701 0.146125 0 -0.98926598 0.400316 0 -0.91637701
		 -0.39776501 0 -0.91748798 -0.39776501 0 -0.91748798 -0.141635 0 -0.98991901 -0.141635
		 0 -0.98991901 -0.39776501 0 -0.91748798 0.146183 0 -0.98925799 0.87667799 0 -0.481078
		 0.87667799 0 -0.481078 0.87667799 0 -0.481078 0.87667799 0 -0.481078 0.87667799 0
		 -0.481078 0.87667799 0 -0.481078 0.88339901 0 0.468622 0.88339901 0 0.468622 0.88339901
		 0 0.468622 0.88339901 0 0.468622 0.88339901 0 0.468622 0.88339901 0 0.468622 -0.141635
		 0 -0.98991901 0.146183 0 -0.98925799 0.40197599 0 -0.91565001 0.40197599 0 -0.91565001
		 0.146183 0 -0.98925799 0.40197599 0 -0.91565001 -0.83546299 1e-006 -0.549546 -0.83546299
		 0 -0.549546 -0.77103198 0 -0.636796 -0.77103198 0 -0.636796 -0.83546299 0 -0.549546
		 -0.69659603 0 -0.71746403 0.963278 0 0.26850799 0.96327698 0 0.26850799 0.96327698
		 0 0.26850799 0.96327698 0 0.26850799 0.96327698 0 0.26850799 0.96327698 0 0.26850799
		 -0.77103198 0 -0.636796 -0.69659603 0 -0.71746403 -0.61479598 0 -0.78868598 -0.61479598
		 0 -0.78868598 -0.69659603 0 -0.71746403 -0.61479598 0 -0.78868598 0.87966102 0 -0.475602
		 0.87966102 0 -0.475602 0.87966102 0 -0.475602 0.87966102 0 -0.475602 0.87966102 0
		 -0.475602 0.87966102 0 -0.475602 0.55794102 0 -0.82988101 0.55794102 0 -0.82988101
		 0.55794102 0 -0.82988101 0.55794102 0 -0.82988101 0.55794102 0 -0.82988101 0.55794102
		 0 -0.82988101 -0.985663 0 0.16872799 -0.985663 0 0.168727 -0.985663 0 0.168727 -0.985663
		 0 0.168727 -0.985663 0 0.168727 -0.985663 0 0.168727 -0.84149402 0 0.54026699 -0.84149402
		 0 0.54026699 -0.84149402 0 0.54026699 -0.84149402 0 0.54026699 -0.84149402 0 0.54026699
		 -0.84149402 0 0.54026699 -0.985663 0 0.168727 -0.985663 0 0.168727 -0.985663 0 0.168727
		 -0.985663 0 0.168727 -0.985663 0 0.168727 -0.985663 0 0.168727 -0.84149402 0 0.54026699
		 -0.84149402 0 0.54026699 -0.84149402 0 0.54026699 -0.84149402 0 0.54026699 -0.84149402
		 0 0.54026699 -0.84149402 0 0.54026699 -0.97373998 0 0.227663 -0.97373998 0 0.227663
		 -0.97373998 0 0.227663 -0.97373998 0 0.227663 -0.97373998 0 0.227663 -0.97373998
		 0 0.227663 -0.85354102 0 0.521025 -0.85354102 0 0.521025 -0.85354102 0 0.521025 -0.85354102
		 0 0.521025 -0.85354102 0 0.521025 -0.85354102 0 0.521025 -0.985663 0 -0.168727 -0.985663
		 0 -0.168727 -0.985663 0 -0.168727 -0.985663 0 -0.168727 -0.985663 0 -0.168727 -0.985663
		 0 -0.168727 -0.48613501 0 -0.87388402 -0.618891 0 -0.78547698 -0.48613501 0 -0.87388402
		 -0.48613501 0 -0.87388402 -0.618891 0 -0.78547698 -0.73878098 0 -0.67394501 -0.618891
		 0 -0.78547698 -0.83653498 0 -0.54791403 -0.73878098 0 -0.67394501 -0.73878098 0 -0.67394501
		 -0.83653498 0 -0.54791403 -0.83653498 0 -0.54791403 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0
		 1 0 0 0.59349197 0 -0.80484003 0.59349197 0 -0.80484003 0.52332097 0 -0.85213602
		 0.52332097 0 -0.85213602 0.59349197 0 -0.80484003 0.44885299 0 -0.89360499 0.52332097
		 0 -0.85213602 0.44885299 0 -0.89360499 0.264801 0 -0.96430302 0.264801 0 -0.96430302;
	setAttr ".n[664:829]" -type "float3"  0.44885299 0 -0.89360499 0.15308601 0
		 -0.988213 0.264801 0 -0.96430302 0.15308601 0 -0.988213 0.040842 0 -0.99916601 0.040842
		 0 -0.99916601 0.15308601 0 -0.988213 0.040842 0 -0.99916601 0.93688399 0 -0.34964001
		 0.93688399 0 -0.34964001 0.93688399 0 -0.34964001 0.93688399 0 -0.34964001 0.93688399
		 0 -0.34964001 0.93688399 0 -0.34964001 0.80755401 0 -0.58979398 0.80755401 0 -0.58979398
		 0.80755401 0 -0.58979398 0.80755401 0 -0.58979398 0.80755401 0 -0.58979398 0.80755401
		 0 -0.58979398 0.985663 0 0.168727 0.985663 0 0.168727 0.985663 0 0.168727 0.985663
		 0 0.168727 0.985663 0 0.168727 0.985663 0 0.168727 0.84149402 -1e-006 0.54026699
		 0.84149402 -1e-006 0.54026699 0.84149402 -1e-006 0.54026699 0.84149402 -1e-006 0.54026699
		 0.84149402 -1e-006 0.54026699 0.84149402 0 0.54026699 0.974563 0 0.224113 0.974563
		 0 0.224113 0.974563 0 0.224113 0.974563 0 0.224113 0.974563 0 0.224113 0.974563 0
		 0.224113 0.80334401 0 0.59551501 0.80334401 0 0.59551501 0.80334401 0 0.59551501
		 0.80334401 0 0.59551501 0.80334401 0 0.59551501 0.80334401 0 0.59551501 0.59349197
		 0 -0.80484003 0.59349197 0 -0.80484003 0.52332097 0 -0.85213602 0.52332097 0 -0.85213602
		 0.59349197 0 -0.80484003 0.44885299 0 -0.89360499 0.52332097 0 -0.85213602 0.44885299
		 0 -0.89360499 0.264801 0 -0.96430302 0.264801 0 -0.96430302 0.44885299 0 -0.89360499
		 0.15308601 0 -0.988213 0.264801 0 -0.96430302 0.15308601 0 -0.988213 0.040842 0 -0.99916601
		 0.040842 0 -0.99916601 0.15308601 0 -0.988213 0.040842 0 -0.99916601 -0.127569 0
		 -0.99182999 -0.127569 0 -0.99182999 -0.127569 0 -0.99182999 -0.127569 0 -0.99182999
		 -0.127569 0 -0.99182999 -0.127569 0 -0.99182999 -0.36311999 0 -0.93174201 -0.36311999
		 0 -0.93174201 -0.36311999 0 -0.93174201 -0.36311999 0 -0.93174201 -0.36311999 0 -0.93174201
		 -0.36311999 0 -0.93174201 -0.529791 0 -0.84812802 -0.529791 0 -0.84812802 -0.529791
		 0 -0.84812802 -0.529791 0 -0.84812802 -0.529791 0 -0.84812802 -0.529791 0 -0.84812802
		 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 -0.35696501 0 -0.93411797 -0.35696501 0 -0.93411797
		 -0.121975 0 -0.99253303 -0.121975 0 -0.99253303 -0.35696501 0 -0.93411797 0.13603599
		 0 -0.990704 0.77988702 0 -0.62592 0.77988702 0 -0.62592 0.77988702 0 -0.62592 0.77988702
		 0 -0.62592 0.77988702 0 -0.62592 0.77988702 0 -0.62592 0.78995103 0 0.61317003 0.78995103
		 0 0.61317003 0.78995103 0 0.61317003 0.78995103 0 0.61317003 0.78995103 0 0.61317003
		 0.78995103 0 0.61317003 -0.121975 0 -0.99253303 0.13603599 0 -0.990704 0.37017399
		 0 -0.92896199 0.37017399 0 -0.92896199 0.13603599 0 -0.990704 0.37017399 0 -0.92896301
		 -0.985663 0 -0.168727 -0.985663 0 -0.16872799 -0.985663 0 -0.16872799 -0.985663 0
		 -0.16872799 -0.985663 0 -0.16872799 -0.985663 0 -0.16872799 -0.84149402 0 -0.54026699
		 -0.84149402 0 -0.54026699 -0.84149402 0 -0.54026699 -0.84149402 0 -0.54026699 -0.84149402
		 0 -0.54026699 -0.84149402 0 -0.54026699 -0.985663 0 -0.168727 -0.985663 0 -0.168727
		 -0.985663 0 -0.168727 -0.985663 0 -0.168727 -0.985663 0 -0.168727 -0.985663 0 -0.168727
		 -0.44721401 0 -0.894427 -0.59790301 0 -0.80156898 -0.44721401 0 -0.894427 -0.44721401
		 0 -0.894427 -0.59790301 0 -0.80156898 -0.73387802 0 -0.679281 -0.59790301 0 -0.80156898
		 -0.84214503 0 -0.53925198 -0.73387802 0 -0.679281 -0.73387802 0 -0.679281 -0.84214503
		 0 -0.53925198 -0.84214503 0 -0.53925198 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0
		 0.985663 0 -0.168727 0.985663 0 -0.16872799 0.985663 0 -0.16872799 0.985663 0 -0.16872799
		 0.985663 0 -0.16872799 0.985663 0 -0.16872799 0.84149402 0 -0.54026699 0.84149402
		 0 -0.54026699 0.84149402 0 -0.54026699 0.84149402 0 -0.54026699 0.84149402 0 -0.54026699
		 0.84149402 0 -0.54026699 0.985663 0 -0.168727 0.985663 0 -0.168727 0.985663 0 -0.168727
		 0.985663 0 -0.168727 0.985663 0 -0.168727 0.985663 0 -0.168727 0.44721401 0 -0.894427
		 0.44721401 0 -0.894427;
	setAttr ".n[830:863]" -type "float3"  0.59790301 0 -0.80156898 0.59790301 0
		 -0.80156898 0.44721401 0 -0.894427 0.73387802 0 -0.679281 0.59790301 0 -0.80156898
		 0.73387802 0 -0.679281 0.84214503 0 -0.53925198 0.84214503 0 -0.53925198 0.73387802
		 0 -0.679281 0.84214503 0 -0.53925198 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 -1e-006 0 0.985663
		 0 0.168727 0.985663 0 0.168727 0.985663 0 0.168727 0.985663 0 0.168727 0.985663 0
		 0.168727 0.985663 0 0.168727 0.35624501 0 0.93439198 0.48271 0 0.87577999 0.35624501
		 0 0.93439198 0.35624501 0 0.93439198 0.48271 0 0.87577999 0.60204297 0 0.798464 0.48271
		 0 0.87577999 0.70722002 0 0.706994 0.60204297 0 0.798464 0.60204297 0 0.798464 0.70722002
		 0 0.706994 0.70722002 0 0.706994;
	setAttr -s 288 ".fc[0:287]" -type "polyFaces" 
		f 3 0 1 2
		mu 0 3 0 1 2
		f 3 -2 3 4
		mu 0 3 2 1 3
		f 3 5 6 7
		mu 0 3 4 5 6
		f 3 -7 8 9
		mu 0 3 6 5 7
		f 3 10 11 12
		mu 0 3 8 9 10
		f 3 -12 13 14
		mu 0 3 10 9 11
		f 3 15 16 17
		mu 0 3 12 13 14
		f 3 -17 18 19
		mu 0 3 14 13 15
		f 3 20 21 22
		mu 0 3 16 17 18
		f 3 -22 23 24
		mu 0 3 18 17 19
		f 3 25 26 27
		mu 0 3 20 21 22
		f 3 -27 28 29
		mu 0 3 22 21 23
		f 3 30 31 32
		mu 0 3 24 25 26
		f 3 -32 33 34
		mu 0 3 26 25 27
		f 3 35 36 37
		mu 0 3 28 29 30
		f 3 -37 38 39
		mu 0 3 30 29 31
		f 3 40 41 42
		mu 0 3 32 33 34
		f 3 -42 43 44
		mu 0 3 34 33 35
		f 3 45 46 47
		mu 0 3 36 37 38
		f 3 -47 48 49
		mu 0 3 38 37 39
		f 3 50 51 52
		mu 0 3 40 41 42
		f 3 -52 53 54
		mu 0 3 42 41 43
		f 3 55 56 57
		mu 0 3 44 45 46
		f 3 -57 58 59
		mu 0 3 46 45 47
		f 3 60 61 62
		mu 0 3 48 49 50
		f 3 -62 63 64
		mu 0 3 50 49 51
		f 3 65 66 67
		mu 0 3 52 53 54
		f 3 -67 68 69
		mu 0 3 54 53 55
		f 3 70 71 72
		mu 0 3 56 57 58
		f 3 -72 73 74
		mu 0 3 58 57 59
		f 3 75 76 77
		mu 0 3 60 61 62
		f 3 -77 78 79
		mu 0 3 62 61 63
		f 3 80 81 82
		mu 0 3 64 65 66
		f 3 -82 83 84
		mu 0 3 66 65 67
		f 3 85 86 87
		mu 0 3 68 69 70
		f 3 -87 88 89
		mu 0 3 70 69 71
		f 3 90 91 92
		mu 0 3 72 73 74
		f 3 -92 93 94
		mu 0 3 74 73 75
		f 3 95 96 97
		mu 0 3 76 77 78
		f 3 -97 98 99
		mu 0 3 78 77 79
		f 3 100 101 102
		mu 0 3 80 81 82
		f 3 -102 103 104
		mu 0 3 82 81 83
		f 3 105 106 107
		mu 0 3 84 85 86
		f 3 -107 108 109
		mu 0 3 86 85 87
		f 3 110 111 112
		mu 0 3 88 89 90
		f 3 -112 113 114
		mu 0 3 90 89 91
		f 3 115 116 117
		mu 0 3 92 93 94
		f 3 -117 118 119
		mu 0 3 94 93 95
		f 3 120 121 122
		mu 0 3 96 97 98
		f 3 -122 123 124
		mu 0 3 98 97 99
		f 3 125 126 127
		mu 0 3 100 101 102
		f 3 -127 128 129
		mu 0 3 102 101 103
		f 3 130 131 132
		mu 0 3 104 105 106
		f 3 -132 133 134
		mu 0 3 106 105 107
		f 3 135 136 137
		mu 0 3 108 109 110
		f 3 -137 138 139
		mu 0 3 110 109 111
		f 3 140 141 142
		mu 0 3 112 113 114
		f 3 -142 143 144
		mu 0 3 114 113 115
		f 3 145 146 147
		mu 0 3 116 117 118
		f 3 -147 148 149
		mu 0 3 118 117 119
		f 3 150 151 152
		mu 0 3 120 121 122
		f 3 -152 153 154
		mu 0 3 122 121 123
		f 3 145 155 156
		mu 0 3 124 125 126
		f 3 -156 157 158
		mu 0 3 126 125 127
		f 3 -150 159 160
		mu 0 3 118 119 128
		f 3 -160 161 -151
		mu 0 3 128 119 129
		f 3 162 163 164
		mu 0 3 130 131 132
		f 3 -164 165 166
		mu 0 3 132 131 133
		f 3 167 168 169
		mu 0 3 134 135 136
		f 3 -169 170 171
		mu 0 3 136 135 137
		f 3 162 172 173
		mu 0 3 138 139 140
		f 3 -173 174 175
		mu 0 3 140 139 141
		f 3 -167 176 177
		mu 0 3 132 133 142
		f 3 -177 178 -168
		mu 0 3 142 133 143
		f 3 179 180 181
		mu 0 3 144 145 146
		f 3 -181 182 183
		mu 0 3 146 145 147
		f 3 184 185 186
		mu 0 3 148 149 150
		f 3 -186 187 188
		mu 0 3 150 149 151
		f 3 179 189 190
		mu 0 3 152 153 154
		f 3 -190 191 192
		mu 0 3 154 153 155
		f 3 -184 193 194
		mu 0 3 146 147 156
		f 3 -194 195 -185
		mu 0 3 156 147 157
		f 3 196 197 198
		mu 0 3 158 159 160
		f 3 -198 199 200
		mu 0 3 160 159 161
		f 3 201 202 203
		mu 0 3 162 163 164
		f 3 -203 204 205
		mu 0 3 164 163 165
		f 3 196 206 207
		mu 0 3 166 167 168
		f 3 -207 208 209
		mu 0 3 168 167 169
		f 3 -201 210 211
		mu 0 3 160 161 170
		f 3 -211 212 -202
		mu 0 3 170 161 171
		f 3 213 214 215
		mu 0 3 172 173 174
		f 3 -215 216 217
		mu 0 3 174 173 175
		f 3 213 218 219
		mu 0 3 176 177 178
		f 3 -219 220 221
		mu 0 3 178 177 179
		f 3 222 223 224
		mu 0 3 180 181 182
		f 3 -224 225 226
		mu 0 3 182 181 183
		f 3 227 228 229
		mu 0 3 184 185 186
		f 3 -229 230 -223
		mu 0 3 186 185 187
		f 3 231 232 233
		mu 0 3 188 189 190
		f 3 -233 234 235
		mu 0 3 190 189 191
		f 3 236 237 238
		mu 0 3 192 193 194
		f 3 -238 239 240
		mu 0 3 194 193 195
		f 3 241 242 243
		mu 0 3 196 197 198
		f 3 -243 244 245
		mu 0 3 198 197 199
		f 3 246 247 248
		mu 0 3 200 201 202
		f 3 -248 249 250
		mu 0 3 202 201 203
		f 3 251 252 253
		mu 0 3 204 205 206
		f 3 -253 254 255
		mu 0 3 206 205 207
		f 3 256 257 258
		mu 0 3 208 209 210
		f 3 -258 259 260
		mu 0 3 210 209 211
		f 3 261 262 263
		mu 0 3 212 213 214
		f 3 -263 264 265
		mu 0 3 214 213 215
		f 3 266 267 268
		mu 0 3 216 217 218
		f 3 -268 269 270
		mu 0 3 218 217 219
		f 3 271 272 273
		mu 0 3 220 221 222
		f 3 -273 274 275
		mu 0 3 222 221 223
		f 3 276 277 278
		mu 0 3 224 225 226
		f 3 -278 279 280
		mu 0 3 226 225 227
		f 3 -281 281 282
		mu 0 3 228 229 230
		f 3 -282 283 284
		mu 0 3 230 229 231
		f 3 285 286 287
		mu 0 3 232 233 234
		f 3 -287 288 289
		mu 0 3 234 233 235
		f 3 290 291 292
		mu 0 3 236 237 238
		f 3 -292 293 294
		mu 0 3 238 237 239
		f 3 295 296 297
		mu 0 3 240 241 242
		f 3 -297 298 299
		mu 0 3 242 241 243
		f 3 300 301 302
		mu 0 3 244 245 246
		f 3 -302 303 304
		mu 0 3 246 245 247
		f 3 305 306 307
		mu 0 3 248 249 250
		f 3 -307 308 309
		mu 0 3 250 249 251
		f 3 310 311 312
		mu 0 3 252 253 254
		f 3 -312 313 314
		mu 0 3 254 253 255
		f 3 315 316 317
		mu 0 3 256 257 258
		f 3 -317 318 319
		mu 0 3 258 257 259
		f 3 320 321 322
		mu 0 3 260 261 262
		f 3 -322 323 324
		mu 0 3 262 261 263
		f 3 325 326 327
		mu 0 3 264 265 266
		f 3 -327 328 329
		mu 0 3 266 265 267
		f 3 330 331 332
		mu 0 3 268 269 270
		f 3 -332 333 334
		mu 0 3 270 269 271
		f 3 335 336 337
		mu 0 3 272 273 274
		f 3 -337 338 339
		mu 0 3 274 273 275
		f 3 340 341 342
		mu 0 3 276 277 278
		f 3 -342 343 344
		mu 0 3 278 277 279
		f 3 345 346 347
		mu 0 3 280 281 282
		f 3 -347 348 349
		mu 0 3 282 281 283
		f 3 350 351 352
		mu 0 3 284 285 286
		f 3 -352 353 354
		mu 0 3 286 285 287
		f 3 355 356 357
		mu 0 3 288 289 290
		f 3 -357 358 359
		mu 0 3 290 289 291
		f 3 360 361 362
		mu 0 3 292 293 294
		f 3 -362 363 364
		mu 0 3 294 293 295
		f 3 365 366 367
		mu 0 3 296 297 298
		f 3 -367 368 369
		mu 0 3 298 297 299
		f 3 370 371 372
		mu 0 3 300 301 302
		f 3 -372 373 374
		mu 0 3 302 301 303
		f 3 375 376 377
		mu 0 3 304 305 306
		f 3 -377 378 379
		mu 0 3 306 305 307
		f 3 380 381 382
		mu 0 3 308 309 310
		f 3 -382 383 384
		mu 0 3 310 309 311
		f 3 375 385 386
		mu 0 3 312 313 314
		f 3 -386 387 388
		mu 0 3 314 313 315
		f 3 -380 389 390
		mu 0 3 306 307 316
		f 3 -390 391 -381
		mu 0 3 316 307 317
		f 3 392 393 394
		mu 0 3 318 319 320
		f 3 -394 395 396
		mu 0 3 320 319 321
		f 3 397 398 399
		mu 0 3 322 323 324
		f 3 -399 400 401
		mu 0 3 324 323 325
		f 3 392 402 403
		mu 0 3 326 327 328
		f 3 -403 404 405
		mu 0 3 328 327 329
		f 3 -397 406 407
		mu 0 3 320 321 330
		f 3 -407 408 -398
		mu 0 3 330 321 331
		f 3 409 410 411
		mu 0 3 332 333 334
		f 3 -411 412 413
		mu 0 3 334 333 335
		f 3 414 415 416
		mu 0 3 336 337 338
		f 3 -416 417 418
		mu 0 3 338 337 339
		f 3 409 419 420
		mu 0 3 340 341 342
		f 3 -420 421 422
		mu 0 3 342 341 343
		f 3 -414 423 424
		mu 0 3 334 335 344
		f 3 -424 425 -415
		mu 0 3 344 335 345
		f 3 426 427 428
		mu 0 3 346 347 348
		f 3 -428 429 430
		mu 0 3 348 347 349
		f 3 431 432 433
		mu 0 3 350 351 352
		f 3 -433 434 435
		mu 0 3 352 351 353
		f 3 426 436 437
		mu 0 3 354 355 356
		f 3 -437 438 439
		mu 0 3 356 355 357
		f 3 -431 440 441
		mu 0 3 348 349 358
		f 3 -441 442 -432
		mu 0 3 358 349 359
		f 3 443 444 445
		mu 0 3 360 361 362
		f 3 -445 446 447
		mu 0 3 362 361 363
		f 3 443 448 449
		mu 0 3 364 365 366
		f 3 -449 450 451
		mu 0 3 366 365 367
		f 3 -448 452 453
		mu 0 3 362 363 368
		f 3 -453 454 455
		mu 0 3 368 363 369
		f 3 456 457 458
		mu 0 3 370 371 372
		f 3 -458 459 460
		mu 0 3 372 371 373
		f 3 461 462 463
		mu 0 3 374 375 376
		f 3 -463 464 -457
		mu 0 3 376 375 377
		f 3 465 466 467
		mu 0 3 378 379 380
		f 3 -467 468 469
		mu 0 3 380 379 381
		f 3 470 471 472
		mu 0 3 382 383 384
		f 3 -472 473 -466
		mu 0 3 384 383 385
		f 3 474 475 476
		mu 0 3 386 387 388
		f 3 -476 477 478
		mu 0 3 388 387 389
		f 3 479 480 481
		mu 0 3 390 391 392
		f 3 -481 482 -475
		mu 0 3 392 391 393
		f 3 483 484 485
		mu 0 3 394 395 396
		f 3 -485 486 487
		mu 0 3 396 395 397
		f 3 488 489 490
		mu 0 3 398 399 400
		f 3 -490 491 -484
		mu 0 3 400 399 401
		f 3 492 493 494
		mu 0 3 402 403 404
		f 3 -494 495 496
		mu 0 3 404 403 405
		f 3 497 498 499
		mu 0 3 406 407 408
		f 3 -499 500 501
		mu 0 3 408 407 409
		f 3 502 503 -501
		mu 0 3 407 410 409
		f 3 -504 -495 504
		mu 0 3 409 410 411
		f 3 505 506 507
		mu 0 3 412 413 414
		f 3 -507 508 509
		mu 0 3 414 413 415
		f 3 510 511 512
		mu 0 3 416 417 418
		f 3 -512 513 514
		mu 0 3 418 417 419
		f 3 -515 515 516
		mu 0 3 418 419 420
		f 3 -516 517 518
		mu 0 3 420 419 421
		f 3 -519 519 520
		mu 0 3 420 421 422
		f 3 -520 521 522
		mu 0 3 422 421 423
		f 3 523 524 525
		mu 0 3 424 425 426
		f 3 -525 526 527
		mu 0 3 426 425 427
		f 3 528 529 530
		mu 0 3 428 429 430
		f 3 -530 531 -524
		mu 0 3 430 429 431
		f 3 532 533 534
		mu 0 3 432 433 434
		f 3 -534 535 536
		mu 0 3 434 433 435
		f 3 537 538 539
		mu 0 3 436 437 438
		f 3 -539 -535 540
		mu 0 3 438 437 439
		f 3 541 542 543
		mu 0 3 440 441 442
		f 3 -543 544 545
		mu 0 3 442 441 443
		f 3 546 547 548
		mu 0 3 444 445 446
		f 3 -548 -544 549
		mu 0 3 446 445 447
		f 3 550 551 552
		mu 0 3 448 449 450
		f 3 -552 553 554
		mu 0 3 450 449 451
		f 3 -555 555 556
		mu 0 3 450 451 452
		f 3 -556 557 558
		mu 0 3 452 451 453
		f 3 -559 559 560
		mu 0 3 452 453 454
		f 3 -560 561 562
		mu 0 3 454 453 455
		f 3 -563 563 564
		mu 0 3 456 457 458
		f 3 -564 565 566
		mu 0 3 458 457 459
		f 3 -567 567 568
		mu 0 3 460 461 462
		f 3 -568 569 570
		mu 0 3 462 461 463
		f 3 -571 571 572
		mu 0 3 464 465 466
		f 3 -572 573 574
		mu 0 3 466 465 467
		f 3 575 576 577
		mu 0 3 468 469 470
		f 3 -577 578 579
		mu 0 3 470 469 471
		f 3 580 581 582
		mu 0 3 472 473 474
		f 3 -582 583 584
		mu 0 3 474 473 475
		f 3 585 586 587
		mu 0 3 476 477 478
		f 3 -587 588 589
		mu 0 3 478 477 479
		f 3 580 590 591
		mu 0 3 480 481 482
		f 3 -591 592 593
		mu 0 3 482 481 483
		f 3 -585 594 595
		mu 0 3 474 475 484
		f 3 -595 596 -586
		mu 0 3 484 475 485
		f 3 597 598 599
		mu 0 3 486 487 488
		f 3 -599 600 601
		mu 0 3 488 487 489
		f 3 602 603 604
		mu 0 3 490 491 492
		f 3 -604 -600 605
		mu 0 3 492 491 493
		f 3 606 607 608
		mu 0 3 494 495 496
		f 3 -608 609 610
		mu 0 3 496 495 497
		f 3 611 612 613
		mu 0 3 498 499 500
		f 3 -613 614 615
		mu 0 3 500 499 501
		f 3 616 617 -615
		mu 0 3 499 502 501
		f 3 -618 -609 618
		mu 0 3 501 502 503
		f 3 619 620 -614
		mu 0 3 504 505 506
		f 3 -621 621 622
		mu 0 3 506 505 507
		f 3 623 624 625
		mu 0 3 508 509 510
		f 3 -625 626 627
		mu 0 3 510 509 511
		f 3 628 629 630
		mu 0 3 512 513 514
		f 3 -630 631 -624
		mu 0 3 514 513 515
		f 3 632 633 634
		mu 0 3 516 517 518
		f 3 -634 635 636
		mu 0 3 518 517 519
		f 3 637 638 639
		mu 0 3 520 521 522
		f 3 -639 640 641
		mu 0 3 522 521 523
		f 3 -642 642 643
		mu 0 3 522 523 524
		f 3 -643 644 -633
		mu 0 3 524 523 525
		f 3 -638 645 646
		mu 0 3 526 527 528
		f 3 -646 647 648
		mu 0 3 528 527 529
		f 3 649 650 651
		mu 0 3 530 531 532
		f 3 -651 652 653
		mu 0 3 532 531 533
		f 3 654 655 656
		mu 0 3 534 535 536
		f 3 -656 657 658
		mu 0 3 536 535 537
		f 3 659 660 -658
		mu 0 3 535 538 537
		f 3 -661 -652 661
		mu 0 3 537 538 539;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -s -n "persp";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 15.639208706991159 37.584242942659365 0.21454100376502211 ;
	setAttr ".r" -type "double3" -67.800000000000566 89.199999999999974 -2.277978513532158e-013 ;
	setAttr ".rpt" -type "double3" 3.7744390147619192e-017 -4.1583478614278593e-017 
		-2.7867463803133243e-018 ;
createNode camera -s -n "perspShape" -p "persp";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999979;
	setAttr ".coi" 40.058088085904011;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".tp" -type "double3" 0.50510454177854669 0.49563750019297004 0.0032153129577636719 ;
	setAttr ".hc" -type "string" "viewSet -p %camera";
createNode transform -s -n "top";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 100.1 0 ;
	setAttr ".r" -type "double3" -89.999999999999986 0 0 ;
createNode camera -s -n "topShape" -p "top";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
createNode transform -s -n "front";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 100.1 ;
createNode camera -s -n "frontShape" -p "front";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
createNode transform -s -n "side";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 100.1 0 0 ;
	setAttr ".r" -type "double3" 0 89.999999999999986 0 ;
createNode camera -s -n "sideShape" -p "side";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
createNode transform -n "polySurface87";
createNode mesh -n "polySurfaceShape87" -p "polySurface87";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode lightLinker -s -n "lightLinker1";
	setAttr -s 2 ".lnk";
	setAttr -s 2 ".slnk";
createNode displayLayerManager -n "layerManager";
	setAttr ".cdl" 1;
	setAttr -s 4 ".dli[3]"  1;
createNode displayLayer -n "defaultLayer";
createNode renderLayerManager -n "renderLayerManager";
createNode renderLayer -n "defaultRenderLayer";
	setAttr ".g" yes;
createNode polySeparate -n "polySeparate1";
	setAttr ".ic" 86;
	setAttr -s 86 ".out";
createNode groupId -n "groupId1";
	setAttr ".ihi" 0;
createNode groupId -n "groupId2";
	setAttr ".ihi" 0;
createNode groupId -n "groupId4";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts2";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId5";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts3";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId6";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts4";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId7";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts5";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId8";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts6";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId9";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts7";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId10";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts8";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId11";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts9";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId12";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts10";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId13";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts11";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId14";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts12";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId15";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts13";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId16";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts14";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId17";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts15";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId18";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts16";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId19";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts17";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId20";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts18";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId21";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts19";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId22";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts20";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId23";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts21";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId24";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts22";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId25";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts23";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId26";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts24";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId27";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts25";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId28";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts26";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId29";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts27";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId30";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts28";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId31";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts29";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId32";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts30";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId33";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts31";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId34";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts32";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId35";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts33";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId36";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts34";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId37";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts35";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId38";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts36";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId39";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts37";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId40";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts38";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId41";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts39";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId42";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts40";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId43";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts41";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId44";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts42";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId45";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts43";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId46";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts44";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId47";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts45";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId48";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts46";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId49";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts47";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId50";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts48";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId51";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts49";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId52";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts50";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId53";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts51";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId54";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts52";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId55";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts53";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId56";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts54";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId57";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts55";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId58";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts56";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId59";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts57";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId60";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts58";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId61";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts59";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId62";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts60";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId63";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts61";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId64";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts62";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId65";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts63";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId66";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts64";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId67";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts65";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId68";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts66";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId69";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts67";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId70";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts68";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 6 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]";
createNode groupId -n "groupId71";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts69";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId72";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts70";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId73";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts71";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId74";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts72";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId75";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts73";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 6 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]";
createNode groupId -n "groupId76";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts74";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId77";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts75";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 6 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]";
createNode groupId -n "groupId78";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts76";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId79";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts77";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId80";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts78";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId81";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts79";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 12 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]" "f[8]" "f[9]" "f[10]" "f[11]";
createNode groupId -n "groupId82";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts80";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId83";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts81";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId84";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts82";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId85";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts83";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId86";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts84";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 4 "f[0]" "f[1]" "f[2]" "f[3]";
createNode groupId -n "groupId87";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts85";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 8 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]";
createNode groupId -n "groupId88";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts86";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 6 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]";
createNode groupParts -n "groupParts1";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 2 "f[0]" "f[1]";
createNode groupId -n "groupId3";
	setAttr ".ihi" 0;
createNode polyUnite -n "polyUnite1";
	setAttr -s 86 ".ip";
	setAttr -s 86 ".im";
createNode groupId -n "groupId89";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts87";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:287]";
createNode script -n "uiConfigurationScriptNode";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"top\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n"
		+ "                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n"
		+ "                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n"
		+ "                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n"
		+ "            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n"
		+ "            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n"
		+ "            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"side\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n"
		+ "                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n"
		+ "                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n"
		+ "                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n"
		+ "            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n"
		+ "            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" == $panelName) {\n"
		+ "\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"front\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n"
		+ "                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n"
		+ "                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n"
		+ "            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n"
		+ "            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n"
		+ "                -wireframeOnShaded 1\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n"
		+ "                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n"
		+ "                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 1\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n"
		+ "            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n"
		+ "            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n"
		+ "            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `outlinerPanel -unParent -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            outlinerEditor -e \n                -showShapes 0\n                -showAttributes 0\n                -showConnected 0\n                -showAnimCurvesOnly 0\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 1\n                -showAssets 1\n                -showContainedOnly 1\n                -showPublishedAsConnected 0\n                -showContainerContents 1\n                -ignoreDagHierarchy 0\n                -expandConnections 0\n"
		+ "                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 0\n                -highlightActive 1\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"defaultSetFilter\" \n                -showSetMembers 1\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n"
		+ "                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n"
		+ "            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n"
		+ "\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"graphEditor\" -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n"
		+ "                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n"
		+ "                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n"
		+ "            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n"
		+ "                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n"
		+ "                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dopeSheetPanel\" -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n"
		+ "                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n"
		+ "                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n"
		+ "                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n"
		+ "                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n"
		+ "                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n"
		+ "\t\t\t$panelName = `scriptedPanel -unParent  -type \"clipEditorPanel\" -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n"
		+ "                -snapValue \"none\" \n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"sequenceEditorPanel\" -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperGraphPanel\" -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n"
		+ "                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n"
		+ "            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperShadePanel\" -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"visorPanel\" -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"createNodePanel\" -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Texture Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"polyTexturePlacementPanel\" -l (localizedPanelLabel(\"UV Texture Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Texture Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"renderWindowPanel\" -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"blendShapePanel\" (localizedPanelLabel(\"Blend Shape\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\tblendShapePanel -unParent -l (localizedPanelLabel(\"Blend Shape\")) -mbv $menusOkayInPanels ;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tblendShapePanel -edit -l (localizedPanelLabel(\"Blend Shape\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynRelEdPanel\" -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"relationshipPanel\" -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"referenceEditorPanel\" -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"componentEditorPanel\" -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynPaintScriptedPanelType\" -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"scriptEditorPanel\" -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-defaultImage \"\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 1\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 1\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        setFocus `paneLayout -q -p1 $gMainPane`;\n        sceneUIReplacement -deleteRemaining;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 24 -ast 1 -aet 48 ";
	setAttr ".st" 6;
select -ne :time1;
	setAttr ".o" 0;
select -ne :renderPartition;
	setAttr -s 2 ".st";
select -ne :initialShadingGroup;
	setAttr -s 89 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 89 ".gn";
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultShaderList1;
	setAttr -s 2 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderingList1;
select -ne :renderGlobalsList1;
select -ne :defaultHardwareRenderGlobals;
	setAttr ".fn" -type "string" "im";
	setAttr ".res" -type "string" "ntsc_4d 646 485 1.333";
connectAttr "groupParts1.og" "polySurfaceShape1.i";
connectAttr "groupId3.id" "polySurfaceShape1.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape1.iog.og[0].gco";
connectAttr "groupParts2.og" "polySurfaceShape2.i";
connectAttr "groupId4.id" "polySurfaceShape2.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape2.iog.og[0].gco";
connectAttr "groupParts3.og" "polySurfaceShape3.i";
connectAttr "groupId5.id" "polySurfaceShape3.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape3.iog.og[0].gco";
connectAttr "groupParts4.og" "polySurfaceShape4.i";
connectAttr "groupId6.id" "polySurfaceShape4.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape4.iog.og[0].gco";
connectAttr "groupParts5.og" "polySurfaceShape5.i";
connectAttr "groupId7.id" "polySurfaceShape5.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape5.iog.og[0].gco";
connectAttr "groupParts6.og" "polySurfaceShape6.i";
connectAttr "groupId8.id" "polySurfaceShape6.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape6.iog.og[0].gco";
connectAttr "groupParts7.og" "polySurfaceShape7.i";
connectAttr "groupId9.id" "polySurfaceShape7.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape7.iog.og[0].gco";
connectAttr "groupParts8.og" "polySurfaceShape8.i";
connectAttr "groupId10.id" "polySurfaceShape8.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape8.iog.og[0].gco";
connectAttr "groupParts9.og" "polySurfaceShape9.i";
connectAttr "groupId11.id" "polySurfaceShape9.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape9.iog.og[0].gco";
connectAttr "groupParts10.og" "polySurfaceShape10.i";
connectAttr "groupId12.id" "polySurfaceShape10.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape10.iog.og[0].gco";
connectAttr "groupParts11.og" "polySurfaceShape11.i";
connectAttr "groupId13.id" "polySurfaceShape11.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape11.iog.og[0].gco";
connectAttr "groupParts12.og" "polySurfaceShape12.i";
connectAttr "groupId14.id" "polySurfaceShape12.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape12.iog.og[0].gco";
connectAttr "groupParts13.og" "polySurfaceShape13.i";
connectAttr "groupId15.id" "polySurfaceShape13.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape13.iog.og[0].gco";
connectAttr "groupParts14.og" "polySurfaceShape14.i";
connectAttr "groupId16.id" "polySurfaceShape14.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape14.iog.og[0].gco";
connectAttr "groupParts15.og" "polySurfaceShape15.i";
connectAttr "groupId17.id" "polySurfaceShape15.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape15.iog.og[0].gco";
connectAttr "groupParts16.og" "polySurfaceShape16.i";
connectAttr "groupId18.id" "polySurfaceShape16.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape16.iog.og[0].gco";
connectAttr "groupParts17.og" "polySurfaceShape17.i";
connectAttr "groupId19.id" "polySurfaceShape17.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape17.iog.og[0].gco";
connectAttr "groupParts18.og" "polySurfaceShape18.i";
connectAttr "groupId20.id" "polySurfaceShape18.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape18.iog.og[0].gco";
connectAttr "groupParts19.og" "polySurfaceShape19.i";
connectAttr "groupId21.id" "polySurfaceShape19.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape19.iog.og[0].gco";
connectAttr "groupParts20.og" "polySurfaceShape20.i";
connectAttr "groupId22.id" "polySurfaceShape20.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape20.iog.og[0].gco";
connectAttr "groupParts21.og" "polySurfaceShape21.i";
connectAttr "groupId23.id" "polySurfaceShape21.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape21.iog.og[0].gco";
connectAttr "groupParts22.og" "polySurfaceShape22.i";
connectAttr "groupId24.id" "polySurfaceShape22.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape22.iog.og[0].gco";
connectAttr "groupParts23.og" "polySurfaceShape23.i";
connectAttr "groupId25.id" "polySurfaceShape23.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape23.iog.og[0].gco";
connectAttr "groupParts24.og" "polySurfaceShape24.i";
connectAttr "groupId26.id" "polySurfaceShape24.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape24.iog.og[0].gco";
connectAttr "groupParts25.og" "polySurfaceShape25.i";
connectAttr "groupId27.id" "polySurfaceShape25.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape25.iog.og[0].gco";
connectAttr "groupParts26.og" "polySurfaceShape26.i";
connectAttr "groupId28.id" "polySurfaceShape26.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape26.iog.og[0].gco";
connectAttr "groupParts27.og" "polySurfaceShape27.i";
connectAttr "groupId29.id" "polySurfaceShape27.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape27.iog.og[0].gco";
connectAttr "groupParts28.og" "polySurfaceShape28.i";
connectAttr "groupId30.id" "polySurfaceShape28.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape28.iog.og[0].gco";
connectAttr "groupParts29.og" "polySurfaceShape29.i";
connectAttr "groupId31.id" "polySurfaceShape29.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape29.iog.og[0].gco";
connectAttr "groupParts30.og" "polySurfaceShape30.i";
connectAttr "groupId32.id" "polySurfaceShape30.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape30.iog.og[0].gco";
connectAttr "groupParts31.og" "polySurfaceShape31.i";
connectAttr "groupId33.id" "polySurfaceShape31.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape31.iog.og[0].gco";
connectAttr "groupParts32.og" "polySurfaceShape32.i";
connectAttr "groupId34.id" "polySurfaceShape32.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape32.iog.og[0].gco";
connectAttr "groupParts33.og" "polySurfaceShape33.i";
connectAttr "groupId35.id" "polySurfaceShape33.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape33.iog.og[0].gco";
connectAttr "groupParts34.og" "polySurfaceShape34.i";
connectAttr "groupId36.id" "polySurfaceShape34.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape34.iog.og[0].gco";
connectAttr "groupParts35.og" "polySurfaceShape35.i";
connectAttr "groupId37.id" "polySurfaceShape35.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape35.iog.og[0].gco";
connectAttr "groupParts36.og" "polySurfaceShape36.i";
connectAttr "groupId38.id" "polySurfaceShape36.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape36.iog.og[0].gco";
connectAttr "groupParts37.og" "polySurfaceShape37.i";
connectAttr "groupId39.id" "polySurfaceShape37.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape37.iog.og[0].gco";
connectAttr "groupParts38.og" "polySurfaceShape38.i";
connectAttr "groupId40.id" "polySurfaceShape38.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape38.iog.og[0].gco";
connectAttr "groupParts39.og" "polySurfaceShape39.i";
connectAttr "groupId41.id" "polySurfaceShape39.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape39.iog.og[0].gco";
connectAttr "groupParts40.og" "polySurfaceShape40.i";
connectAttr "groupId42.id" "polySurfaceShape40.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape40.iog.og[0].gco";
connectAttr "groupParts41.og" "polySurfaceShape41.i";
connectAttr "groupId43.id" "polySurfaceShape41.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape41.iog.og[0].gco";
connectAttr "groupParts42.og" "polySurfaceShape42.i";
connectAttr "groupId44.id" "polySurfaceShape42.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape42.iog.og[0].gco";
connectAttr "groupParts43.og" "polySurfaceShape43.i";
connectAttr "groupId45.id" "polySurfaceShape43.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape43.iog.og[0].gco";
connectAttr "groupParts44.og" "polySurfaceShape44.i";
connectAttr "groupId46.id" "polySurfaceShape44.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape44.iog.og[0].gco";
connectAttr "groupParts45.og" "polySurfaceShape45.i";
connectAttr "groupId47.id" "polySurfaceShape45.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape45.iog.og[0].gco";
connectAttr "groupParts46.og" "polySurfaceShape46.i";
connectAttr "groupId48.id" "polySurfaceShape46.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape46.iog.og[0].gco";
connectAttr "groupParts47.og" "polySurfaceShape47.i";
connectAttr "groupId49.id" "polySurfaceShape47.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape47.iog.og[0].gco";
connectAttr "groupParts48.og" "polySurfaceShape48.i";
connectAttr "groupId50.id" "polySurfaceShape48.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape48.iog.og[0].gco";
connectAttr "groupParts49.og" "polySurfaceShape49.i";
connectAttr "groupId51.id" "polySurfaceShape49.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape49.iog.og[0].gco";
connectAttr "groupParts50.og" "polySurfaceShape50.i";
connectAttr "groupId52.id" "polySurfaceShape50.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape50.iog.og[0].gco";
connectAttr "groupParts51.og" "polySurfaceShape51.i";
connectAttr "groupId53.id" "polySurfaceShape51.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape51.iog.og[0].gco";
connectAttr "groupParts52.og" "polySurfaceShape52.i";
connectAttr "groupId54.id" "polySurfaceShape52.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape52.iog.og[0].gco";
connectAttr "groupParts53.og" "polySurfaceShape53.i";
connectAttr "groupId55.id" "polySurfaceShape53.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape53.iog.og[0].gco";
connectAttr "groupParts54.og" "polySurfaceShape54.i";
connectAttr "groupId56.id" "polySurfaceShape54.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape54.iog.og[0].gco";
connectAttr "groupParts55.og" "polySurfaceShape55.i";
connectAttr "groupId57.id" "polySurfaceShape55.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape55.iog.og[0].gco";
connectAttr "groupParts56.og" "polySurfaceShape56.i";
connectAttr "groupId58.id" "polySurfaceShape56.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape56.iog.og[0].gco";
connectAttr "groupParts57.og" "polySurfaceShape57.i";
connectAttr "groupId59.id" "polySurfaceShape57.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape57.iog.og[0].gco";
connectAttr "groupParts58.og" "polySurfaceShape58.i";
connectAttr "groupId60.id" "polySurfaceShape58.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape58.iog.og[0].gco";
connectAttr "groupParts59.og" "polySurfaceShape59.i";
connectAttr "groupId61.id" "polySurfaceShape59.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape59.iog.og[0].gco";
connectAttr "groupParts60.og" "polySurfaceShape60.i";
connectAttr "groupId62.id" "polySurfaceShape60.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape60.iog.og[0].gco";
connectAttr "groupParts61.og" "polySurfaceShape61.i";
connectAttr "groupId63.id" "polySurfaceShape61.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape61.iog.og[0].gco";
connectAttr "groupParts62.og" "polySurfaceShape62.i";
connectAttr "groupId64.id" "polySurfaceShape62.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape62.iog.og[0].gco";
connectAttr "groupParts63.og" "polySurfaceShape63.i";
connectAttr "groupId65.id" "polySurfaceShape63.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape63.iog.og[0].gco";
connectAttr "groupParts64.og" "polySurfaceShape64.i";
connectAttr "groupId66.id" "polySurfaceShape64.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape64.iog.og[0].gco";
connectAttr "groupParts65.og" "polySurfaceShape65.i";
connectAttr "groupId67.id" "polySurfaceShape65.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape65.iog.og[0].gco";
connectAttr "groupParts66.og" "polySurfaceShape66.i";
connectAttr "groupId68.id" "polySurfaceShape66.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape66.iog.og[0].gco";
connectAttr "groupParts67.og" "polySurfaceShape67.i";
connectAttr "groupId69.id" "polySurfaceShape67.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape67.iog.og[0].gco";
connectAttr "groupParts68.og" "polySurfaceShape68.i";
connectAttr "groupId70.id" "polySurfaceShape68.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape68.iog.og[0].gco";
connectAttr "groupParts69.og" "polySurfaceShape69.i";
connectAttr "groupId71.id" "polySurfaceShape69.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape69.iog.og[0].gco";
connectAttr "groupParts70.og" "polySurfaceShape70.i";
connectAttr "groupId72.id" "polySurfaceShape70.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape70.iog.og[0].gco";
connectAttr "groupParts71.og" "polySurfaceShape71.i";
connectAttr "groupId73.id" "polySurfaceShape71.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape71.iog.og[0].gco";
connectAttr "groupParts72.og" "polySurfaceShape72.i";
connectAttr "groupId74.id" "polySurfaceShape72.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape72.iog.og[0].gco";
connectAttr "groupParts73.og" "polySurfaceShape73.i";
connectAttr "groupId75.id" "polySurfaceShape73.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape73.iog.og[0].gco";
connectAttr "groupParts74.og" "polySurfaceShape74.i";
connectAttr "groupId76.id" "polySurfaceShape74.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape74.iog.og[0].gco";
connectAttr "groupParts75.og" "polySurfaceShape75.i";
connectAttr "groupId77.id" "polySurfaceShape75.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape75.iog.og[0].gco";
connectAttr "groupParts76.og" "polySurfaceShape76.i";
connectAttr "groupId78.id" "polySurfaceShape76.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape76.iog.og[0].gco";
connectAttr "groupParts77.og" "polySurfaceShape77.i";
connectAttr "groupId79.id" "polySurfaceShape77.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape77.iog.og[0].gco";
connectAttr "groupParts78.og" "polySurfaceShape78.i";
connectAttr "groupId80.id" "polySurfaceShape78.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape78.iog.og[0].gco";
connectAttr "groupParts79.og" "polySurfaceShape79.i";
connectAttr "groupId81.id" "polySurfaceShape79.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape79.iog.og[0].gco";
connectAttr "groupParts80.og" "polySurfaceShape80.i";
connectAttr "groupId82.id" "polySurfaceShape80.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape80.iog.og[0].gco";
connectAttr "groupParts81.og" "polySurfaceShape81.i";
connectAttr "groupId83.id" "polySurfaceShape81.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape81.iog.og[0].gco";
connectAttr "groupParts82.og" "polySurfaceShape82.i";
connectAttr "groupId84.id" "polySurfaceShape82.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape82.iog.og[0].gco";
connectAttr "groupParts83.og" "polySurfaceShape83.i";
connectAttr "groupId85.id" "polySurfaceShape83.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape83.iog.og[0].gco";
connectAttr "groupParts84.og" "polySurfaceShape84.i";
connectAttr "groupId86.id" "polySurfaceShape84.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape84.iog.og[0].gco";
connectAttr "groupParts85.og" "polySurfaceShape85.i";
connectAttr "groupId87.id" "polySurfaceShape85.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape85.iog.og[0].gco";
connectAttr "groupParts86.og" "polySurfaceShape86.i";
connectAttr "groupId88.id" "polySurfaceShape86.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape86.iog.og[0].gco";
connectAttr "groupId1.id" "MeshShape.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "MeshShape.iog.og[0].gco";
connectAttr "groupId2.id" "MeshShape.ciog.cog[0].cgid";
connectAttr "groupParts87.og" "polySurfaceShape87.i";
connectAttr "groupId89.id" "polySurfaceShape87.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape87.iog.og[0].gco";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "MeshShape.o" "polySeparate1.ip";
connectAttr "polySeparate1.out[1]" "groupParts2.ig";
connectAttr "groupId4.id" "groupParts2.gi";
connectAttr "polySeparate1.out[2]" "groupParts3.ig";
connectAttr "groupId5.id" "groupParts3.gi";
connectAttr "polySeparate1.out[3]" "groupParts4.ig";
connectAttr "groupId6.id" "groupParts4.gi";
connectAttr "polySeparate1.out[4]" "groupParts5.ig";
connectAttr "groupId7.id" "groupParts5.gi";
connectAttr "polySeparate1.out[5]" "groupParts6.ig";
connectAttr "groupId8.id" "groupParts6.gi";
connectAttr "polySeparate1.out[6]" "groupParts7.ig";
connectAttr "groupId9.id" "groupParts7.gi";
connectAttr "polySeparate1.out[7]" "groupParts8.ig";
connectAttr "groupId10.id" "groupParts8.gi";
connectAttr "polySeparate1.out[8]" "groupParts9.ig";
connectAttr "groupId11.id" "groupParts9.gi";
connectAttr "polySeparate1.out[9]" "groupParts10.ig";
connectAttr "groupId12.id" "groupParts10.gi";
connectAttr "polySeparate1.out[10]" "groupParts11.ig";
connectAttr "groupId13.id" "groupParts11.gi";
connectAttr "polySeparate1.out[11]" "groupParts12.ig";
connectAttr "groupId14.id" "groupParts12.gi";
connectAttr "polySeparate1.out[12]" "groupParts13.ig";
connectAttr "groupId15.id" "groupParts13.gi";
connectAttr "polySeparate1.out[13]" "groupParts14.ig";
connectAttr "groupId16.id" "groupParts14.gi";
connectAttr "polySeparate1.out[14]" "groupParts15.ig";
connectAttr "groupId17.id" "groupParts15.gi";
connectAttr "polySeparate1.out[15]" "groupParts16.ig";
connectAttr "groupId18.id" "groupParts16.gi";
connectAttr "polySeparate1.out[16]" "groupParts17.ig";
connectAttr "groupId19.id" "groupParts17.gi";
connectAttr "polySeparate1.out[17]" "groupParts18.ig";
connectAttr "groupId20.id" "groupParts18.gi";
connectAttr "polySeparate1.out[18]" "groupParts19.ig";
connectAttr "groupId21.id" "groupParts19.gi";
connectAttr "polySeparate1.out[19]" "groupParts20.ig";
connectAttr "groupId22.id" "groupParts20.gi";
connectAttr "polySeparate1.out[20]" "groupParts21.ig";
connectAttr "groupId23.id" "groupParts21.gi";
connectAttr "polySeparate1.out[21]" "groupParts22.ig";
connectAttr "groupId24.id" "groupParts22.gi";
connectAttr "polySeparate1.out[22]" "groupParts23.ig";
connectAttr "groupId25.id" "groupParts23.gi";
connectAttr "polySeparate1.out[23]" "groupParts24.ig";
connectAttr "groupId26.id" "groupParts24.gi";
connectAttr "polySeparate1.out[24]" "groupParts25.ig";
connectAttr "groupId27.id" "groupParts25.gi";
connectAttr "polySeparate1.out[25]" "groupParts26.ig";
connectAttr "groupId28.id" "groupParts26.gi";
connectAttr "polySeparate1.out[26]" "groupParts27.ig";
connectAttr "groupId29.id" "groupParts27.gi";
connectAttr "polySeparate1.out[27]" "groupParts28.ig";
connectAttr "groupId30.id" "groupParts28.gi";
connectAttr "polySeparate1.out[28]" "groupParts29.ig";
connectAttr "groupId31.id" "groupParts29.gi";
connectAttr "polySeparate1.out[29]" "groupParts30.ig";
connectAttr "groupId32.id" "groupParts30.gi";
connectAttr "polySeparate1.out[30]" "groupParts31.ig";
connectAttr "groupId33.id" "groupParts31.gi";
connectAttr "polySeparate1.out[31]" "groupParts32.ig";
connectAttr "groupId34.id" "groupParts32.gi";
connectAttr "polySeparate1.out[32]" "groupParts33.ig";
connectAttr "groupId35.id" "groupParts33.gi";
connectAttr "polySeparate1.out[33]" "groupParts34.ig";
connectAttr "groupId36.id" "groupParts34.gi";
connectAttr "polySeparate1.out[34]" "groupParts35.ig";
connectAttr "groupId37.id" "groupParts35.gi";
connectAttr "polySeparate1.out[35]" "groupParts36.ig";
connectAttr "groupId38.id" "groupParts36.gi";
connectAttr "polySeparate1.out[36]" "groupParts37.ig";
connectAttr "groupId39.id" "groupParts37.gi";
connectAttr "polySeparate1.out[37]" "groupParts38.ig";
connectAttr "groupId40.id" "groupParts38.gi";
connectAttr "polySeparate1.out[38]" "groupParts39.ig";
connectAttr "groupId41.id" "groupParts39.gi";
connectAttr "polySeparate1.out[39]" "groupParts40.ig";
connectAttr "groupId42.id" "groupParts40.gi";
connectAttr "polySeparate1.out[40]" "groupParts41.ig";
connectAttr "groupId43.id" "groupParts41.gi";
connectAttr "polySeparate1.out[41]" "groupParts42.ig";
connectAttr "groupId44.id" "groupParts42.gi";
connectAttr "polySeparate1.out[42]" "groupParts43.ig";
connectAttr "groupId45.id" "groupParts43.gi";
connectAttr "polySeparate1.out[43]" "groupParts44.ig";
connectAttr "groupId46.id" "groupParts44.gi";
connectAttr "polySeparate1.out[44]" "groupParts45.ig";
connectAttr "groupId47.id" "groupParts45.gi";
connectAttr "polySeparate1.out[45]" "groupParts46.ig";
connectAttr "groupId48.id" "groupParts46.gi";
connectAttr "polySeparate1.out[46]" "groupParts47.ig";
connectAttr "groupId49.id" "groupParts47.gi";
connectAttr "polySeparate1.out[47]" "groupParts48.ig";
connectAttr "groupId50.id" "groupParts48.gi";
connectAttr "polySeparate1.out[48]" "groupParts49.ig";
connectAttr "groupId51.id" "groupParts49.gi";
connectAttr "polySeparate1.out[49]" "groupParts50.ig";
connectAttr "groupId52.id" "groupParts50.gi";
connectAttr "polySeparate1.out[50]" "groupParts51.ig";
connectAttr "groupId53.id" "groupParts51.gi";
connectAttr "polySeparate1.out[51]" "groupParts52.ig";
connectAttr "groupId54.id" "groupParts52.gi";
connectAttr "polySeparate1.out[52]" "groupParts53.ig";
connectAttr "groupId55.id" "groupParts53.gi";
connectAttr "polySeparate1.out[53]" "groupParts54.ig";
connectAttr "groupId56.id" "groupParts54.gi";
connectAttr "polySeparate1.out[54]" "groupParts55.ig";
connectAttr "groupId57.id" "groupParts55.gi";
connectAttr "polySeparate1.out[55]" "groupParts56.ig";
connectAttr "groupId58.id" "groupParts56.gi";
connectAttr "polySeparate1.out[56]" "groupParts57.ig";
connectAttr "groupId59.id" "groupParts57.gi";
connectAttr "polySeparate1.out[57]" "groupParts58.ig";
connectAttr "groupId60.id" "groupParts58.gi";
connectAttr "polySeparate1.out[58]" "groupParts59.ig";
connectAttr "groupId61.id" "groupParts59.gi";
connectAttr "polySeparate1.out[59]" "groupParts60.ig";
connectAttr "groupId62.id" "groupParts60.gi";
connectAttr "polySeparate1.out[60]" "groupParts61.ig";
connectAttr "groupId63.id" "groupParts61.gi";
connectAttr "polySeparate1.out[61]" "groupParts62.ig";
connectAttr "groupId64.id" "groupParts62.gi";
connectAttr "polySeparate1.out[62]" "groupParts63.ig";
connectAttr "groupId65.id" "groupParts63.gi";
connectAttr "polySeparate1.out[63]" "groupParts64.ig";
connectAttr "groupId66.id" "groupParts64.gi";
connectAttr "polySeparate1.out[64]" "groupParts65.ig";
connectAttr "groupId67.id" "groupParts65.gi";
connectAttr "polySeparate1.out[65]" "groupParts66.ig";
connectAttr "groupId68.id" "groupParts66.gi";
connectAttr "polySeparate1.out[66]" "groupParts67.ig";
connectAttr "groupId69.id" "groupParts67.gi";
connectAttr "polySeparate1.out[67]" "groupParts68.ig";
connectAttr "groupId70.id" "groupParts68.gi";
connectAttr "polySeparate1.out[68]" "groupParts69.ig";
connectAttr "groupId71.id" "groupParts69.gi";
connectAttr "polySeparate1.out[69]" "groupParts70.ig";
connectAttr "groupId72.id" "groupParts70.gi";
connectAttr "polySeparate1.out[70]" "groupParts71.ig";
connectAttr "groupId73.id" "groupParts71.gi";
connectAttr "polySeparate1.out[71]" "groupParts72.ig";
connectAttr "groupId74.id" "groupParts72.gi";
connectAttr "polySeparate1.out[72]" "groupParts73.ig";
connectAttr "groupId75.id" "groupParts73.gi";
connectAttr "polySeparate1.out[73]" "groupParts74.ig";
connectAttr "groupId76.id" "groupParts74.gi";
connectAttr "polySeparate1.out[74]" "groupParts75.ig";
connectAttr "groupId77.id" "groupParts75.gi";
connectAttr "polySeparate1.out[75]" "groupParts76.ig";
connectAttr "groupId78.id" "groupParts76.gi";
connectAttr "polySeparate1.out[76]" "groupParts77.ig";
connectAttr "groupId79.id" "groupParts77.gi";
connectAttr "polySeparate1.out[77]" "groupParts78.ig";
connectAttr "groupId80.id" "groupParts78.gi";
connectAttr "polySeparate1.out[78]" "groupParts79.ig";
connectAttr "groupId81.id" "groupParts79.gi";
connectAttr "polySeparate1.out[79]" "groupParts80.ig";
connectAttr "groupId82.id" "groupParts80.gi";
connectAttr "polySeparate1.out[80]" "groupParts81.ig";
connectAttr "groupId83.id" "groupParts81.gi";
connectAttr "polySeparate1.out[81]" "groupParts82.ig";
connectAttr "groupId84.id" "groupParts82.gi";
connectAttr "polySeparate1.out[82]" "groupParts83.ig";
connectAttr "groupId85.id" "groupParts83.gi";
connectAttr "polySeparate1.out[83]" "groupParts84.ig";
connectAttr "groupId86.id" "groupParts84.gi";
connectAttr "polySeparate1.out[84]" "groupParts85.ig";
connectAttr "groupId87.id" "groupParts85.gi";
connectAttr "polySeparate1.out[85]" "groupParts86.ig";
connectAttr "groupId88.id" "groupParts86.gi";
connectAttr "polySeparate1.out[0]" "groupParts1.ig";
connectAttr "groupId3.id" "groupParts1.gi";
connectAttr "polySurfaceShape1.o" "polyUnite1.ip[0]";
connectAttr "polySurfaceShape2.o" "polyUnite1.ip[1]";
connectAttr "polySurfaceShape3.o" "polyUnite1.ip[2]";
connectAttr "polySurfaceShape4.o" "polyUnite1.ip[3]";
connectAttr "polySurfaceShape5.o" "polyUnite1.ip[4]";
connectAttr "polySurfaceShape6.o" "polyUnite1.ip[5]";
connectAttr "polySurfaceShape7.o" "polyUnite1.ip[6]";
connectAttr "polySurfaceShape8.o" "polyUnite1.ip[7]";
connectAttr "polySurfaceShape9.o" "polyUnite1.ip[8]";
connectAttr "polySurfaceShape10.o" "polyUnite1.ip[9]";
connectAttr "polySurfaceShape11.o" "polyUnite1.ip[10]";
connectAttr "polySurfaceShape12.o" "polyUnite1.ip[11]";
connectAttr "polySurfaceShape13.o" "polyUnite1.ip[12]";
connectAttr "polySurfaceShape14.o" "polyUnite1.ip[13]";
connectAttr "polySurfaceShape15.o" "polyUnite1.ip[14]";
connectAttr "polySurfaceShape16.o" "polyUnite1.ip[15]";
connectAttr "polySurfaceShape17.o" "polyUnite1.ip[16]";
connectAttr "polySurfaceShape18.o" "polyUnite1.ip[17]";
connectAttr "polySurfaceShape19.o" "polyUnite1.ip[18]";
connectAttr "polySurfaceShape20.o" "polyUnite1.ip[19]";
connectAttr "polySurfaceShape21.o" "polyUnite1.ip[20]";
connectAttr "polySurfaceShape22.o" "polyUnite1.ip[21]";
connectAttr "polySurfaceShape23.o" "polyUnite1.ip[22]";
connectAttr "polySurfaceShape24.o" "polyUnite1.ip[23]";
connectAttr "polySurfaceShape25.o" "polyUnite1.ip[24]";
connectAttr "polySurfaceShape26.o" "polyUnite1.ip[25]";
connectAttr "polySurfaceShape27.o" "polyUnite1.ip[26]";
connectAttr "polySurfaceShape28.o" "polyUnite1.ip[27]";
connectAttr "polySurfaceShape29.o" "polyUnite1.ip[28]";
connectAttr "polySurfaceShape30.o" "polyUnite1.ip[29]";
connectAttr "polySurfaceShape31.o" "polyUnite1.ip[30]";
connectAttr "polySurfaceShape32.o" "polyUnite1.ip[31]";
connectAttr "polySurfaceShape33.o" "polyUnite1.ip[32]";
connectAttr "polySurfaceShape34.o" "polyUnite1.ip[33]";
connectAttr "polySurfaceShape35.o" "polyUnite1.ip[34]";
connectAttr "polySurfaceShape36.o" "polyUnite1.ip[35]";
connectAttr "polySurfaceShape37.o" "polyUnite1.ip[36]";
connectAttr "polySurfaceShape38.o" "polyUnite1.ip[37]";
connectAttr "polySurfaceShape39.o" "polyUnite1.ip[38]";
connectAttr "polySurfaceShape40.o" "polyUnite1.ip[39]";
connectAttr "polySurfaceShape41.o" "polyUnite1.ip[40]";
connectAttr "polySurfaceShape42.o" "polyUnite1.ip[41]";
connectAttr "polySurfaceShape43.o" "polyUnite1.ip[42]";
connectAttr "polySurfaceShape44.o" "polyUnite1.ip[43]";
connectAttr "polySurfaceShape45.o" "polyUnite1.ip[44]";
connectAttr "polySurfaceShape46.o" "polyUnite1.ip[45]";
connectAttr "polySurfaceShape47.o" "polyUnite1.ip[46]";
connectAttr "polySurfaceShape48.o" "polyUnite1.ip[47]";
connectAttr "polySurfaceShape49.o" "polyUnite1.ip[48]";
connectAttr "polySurfaceShape50.o" "polyUnite1.ip[49]";
connectAttr "polySurfaceShape51.o" "polyUnite1.ip[50]";
connectAttr "polySurfaceShape52.o" "polyUnite1.ip[51]";
connectAttr "polySurfaceShape53.o" "polyUnite1.ip[52]";
connectAttr "polySurfaceShape54.o" "polyUnite1.ip[53]";
connectAttr "polySurfaceShape55.o" "polyUnite1.ip[54]";
connectAttr "polySurfaceShape56.o" "polyUnite1.ip[55]";
connectAttr "polySurfaceShape57.o" "polyUnite1.ip[56]";
connectAttr "polySurfaceShape58.o" "polyUnite1.ip[57]";
connectAttr "polySurfaceShape59.o" "polyUnite1.ip[58]";
connectAttr "polySurfaceShape60.o" "polyUnite1.ip[59]";
connectAttr "polySurfaceShape61.o" "polyUnite1.ip[60]";
connectAttr "polySurfaceShape62.o" "polyUnite1.ip[61]";
connectAttr "polySurfaceShape63.o" "polyUnite1.ip[62]";
connectAttr "polySurfaceShape64.o" "polyUnite1.ip[63]";
connectAttr "polySurfaceShape65.o" "polyUnite1.ip[64]";
connectAttr "polySurfaceShape66.o" "polyUnite1.ip[65]";
connectAttr "polySurfaceShape67.o" "polyUnite1.ip[66]";
connectAttr "polySurfaceShape68.o" "polyUnite1.ip[67]";
connectAttr "polySurfaceShape69.o" "polyUnite1.ip[68]";
connectAttr "polySurfaceShape70.o" "polyUnite1.ip[69]";
connectAttr "polySurfaceShape71.o" "polyUnite1.ip[70]";
connectAttr "polySurfaceShape72.o" "polyUnite1.ip[71]";
connectAttr "polySurfaceShape73.o" "polyUnite1.ip[72]";
connectAttr "polySurfaceShape74.o" "polyUnite1.ip[73]";
connectAttr "polySurfaceShape75.o" "polyUnite1.ip[74]";
connectAttr "polySurfaceShape76.o" "polyUnite1.ip[75]";
connectAttr "polySurfaceShape77.o" "polyUnite1.ip[76]";
connectAttr "polySurfaceShape78.o" "polyUnite1.ip[77]";
connectAttr "polySurfaceShape79.o" "polyUnite1.ip[78]";
connectAttr "polySurfaceShape80.o" "polyUnite1.ip[79]";
connectAttr "polySurfaceShape81.o" "polyUnite1.ip[80]";
connectAttr "polySurfaceShape82.o" "polyUnite1.ip[81]";
connectAttr "polySurfaceShape83.o" "polyUnite1.ip[82]";
connectAttr "polySurfaceShape84.o" "polyUnite1.ip[83]";
connectAttr "polySurfaceShape85.o" "polyUnite1.ip[84]";
connectAttr "polySurfaceShape86.o" "polyUnite1.ip[85]";
connectAttr "polySurfaceShape1.wm" "polyUnite1.im[0]";
connectAttr "polySurfaceShape2.wm" "polyUnite1.im[1]";
connectAttr "polySurfaceShape3.wm" "polyUnite1.im[2]";
connectAttr "polySurfaceShape4.wm" "polyUnite1.im[3]";
connectAttr "polySurfaceShape5.wm" "polyUnite1.im[4]";
connectAttr "polySurfaceShape6.wm" "polyUnite1.im[5]";
connectAttr "polySurfaceShape7.wm" "polyUnite1.im[6]";
connectAttr "polySurfaceShape8.wm" "polyUnite1.im[7]";
connectAttr "polySurfaceShape9.wm" "polyUnite1.im[8]";
connectAttr "polySurfaceShape10.wm" "polyUnite1.im[9]";
connectAttr "polySurfaceShape11.wm" "polyUnite1.im[10]";
connectAttr "polySurfaceShape12.wm" "polyUnite1.im[11]";
connectAttr "polySurfaceShape13.wm" "polyUnite1.im[12]";
connectAttr "polySurfaceShape14.wm" "polyUnite1.im[13]";
connectAttr "polySurfaceShape15.wm" "polyUnite1.im[14]";
connectAttr "polySurfaceShape16.wm" "polyUnite1.im[15]";
connectAttr "polySurfaceShape17.wm" "polyUnite1.im[16]";
connectAttr "polySurfaceShape18.wm" "polyUnite1.im[17]";
connectAttr "polySurfaceShape19.wm" "polyUnite1.im[18]";
connectAttr "polySurfaceShape20.wm" "polyUnite1.im[19]";
connectAttr "polySurfaceShape21.wm" "polyUnite1.im[20]";
connectAttr "polySurfaceShape22.wm" "polyUnite1.im[21]";
connectAttr "polySurfaceShape23.wm" "polyUnite1.im[22]";
connectAttr "polySurfaceShape24.wm" "polyUnite1.im[23]";
connectAttr "polySurfaceShape25.wm" "polyUnite1.im[24]";
connectAttr "polySurfaceShape26.wm" "polyUnite1.im[25]";
connectAttr "polySurfaceShape27.wm" "polyUnite1.im[26]";
connectAttr "polySurfaceShape28.wm" "polyUnite1.im[27]";
connectAttr "polySurfaceShape29.wm" "polyUnite1.im[28]";
connectAttr "polySurfaceShape30.wm" "polyUnite1.im[29]";
connectAttr "polySurfaceShape31.wm" "polyUnite1.im[30]";
connectAttr "polySurfaceShape32.wm" "polyUnite1.im[31]";
connectAttr "polySurfaceShape33.wm" "polyUnite1.im[32]";
connectAttr "polySurfaceShape34.wm" "polyUnite1.im[33]";
connectAttr "polySurfaceShape35.wm" "polyUnite1.im[34]";
connectAttr "polySurfaceShape36.wm" "polyUnite1.im[35]";
connectAttr "polySurfaceShape37.wm" "polyUnite1.im[36]";
connectAttr "polySurfaceShape38.wm" "polyUnite1.im[37]";
connectAttr "polySurfaceShape39.wm" "polyUnite1.im[38]";
connectAttr "polySurfaceShape40.wm" "polyUnite1.im[39]";
connectAttr "polySurfaceShape41.wm" "polyUnite1.im[40]";
connectAttr "polySurfaceShape42.wm" "polyUnite1.im[41]";
connectAttr "polySurfaceShape43.wm" "polyUnite1.im[42]";
connectAttr "polySurfaceShape44.wm" "polyUnite1.im[43]";
connectAttr "polySurfaceShape45.wm" "polyUnite1.im[44]";
connectAttr "polySurfaceShape46.wm" "polyUnite1.im[45]";
connectAttr "polySurfaceShape47.wm" "polyUnite1.im[46]";
connectAttr "polySurfaceShape48.wm" "polyUnite1.im[47]";
connectAttr "polySurfaceShape49.wm" "polyUnite1.im[48]";
connectAttr "polySurfaceShape50.wm" "polyUnite1.im[49]";
connectAttr "polySurfaceShape51.wm" "polyUnite1.im[50]";
connectAttr "polySurfaceShape52.wm" "polyUnite1.im[51]";
connectAttr "polySurfaceShape53.wm" "polyUnite1.im[52]";
connectAttr "polySurfaceShape54.wm" "polyUnite1.im[53]";
connectAttr "polySurfaceShape55.wm" "polyUnite1.im[54]";
connectAttr "polySurfaceShape56.wm" "polyUnite1.im[55]";
connectAttr "polySurfaceShape57.wm" "polyUnite1.im[56]";
connectAttr "polySurfaceShape58.wm" "polyUnite1.im[57]";
connectAttr "polySurfaceShape59.wm" "polyUnite1.im[58]";
connectAttr "polySurfaceShape60.wm" "polyUnite1.im[59]";
connectAttr "polySurfaceShape61.wm" "polyUnite1.im[60]";
connectAttr "polySurfaceShape62.wm" "polyUnite1.im[61]";
connectAttr "polySurfaceShape63.wm" "polyUnite1.im[62]";
connectAttr "polySurfaceShape64.wm" "polyUnite1.im[63]";
connectAttr "polySurfaceShape65.wm" "polyUnite1.im[64]";
connectAttr "polySurfaceShape66.wm" "polyUnite1.im[65]";
connectAttr "polySurfaceShape67.wm" "polyUnite1.im[66]";
connectAttr "polySurfaceShape68.wm" "polyUnite1.im[67]";
connectAttr "polySurfaceShape69.wm" "polyUnite1.im[68]";
connectAttr "polySurfaceShape70.wm" "polyUnite1.im[69]";
connectAttr "polySurfaceShape71.wm" "polyUnite1.im[70]";
connectAttr "polySurfaceShape72.wm" "polyUnite1.im[71]";
connectAttr "polySurfaceShape73.wm" "polyUnite1.im[72]";
connectAttr "polySurfaceShape74.wm" "polyUnite1.im[73]";
connectAttr "polySurfaceShape75.wm" "polyUnite1.im[74]";
connectAttr "polySurfaceShape76.wm" "polyUnite1.im[75]";
connectAttr "polySurfaceShape77.wm" "polyUnite1.im[76]";
connectAttr "polySurfaceShape78.wm" "polyUnite1.im[77]";
connectAttr "polySurfaceShape79.wm" "polyUnite1.im[78]";
connectAttr "polySurfaceShape80.wm" "polyUnite1.im[79]";
connectAttr "polySurfaceShape81.wm" "polyUnite1.im[80]";
connectAttr "polySurfaceShape82.wm" "polyUnite1.im[81]";
connectAttr "polySurfaceShape83.wm" "polyUnite1.im[82]";
connectAttr "polySurfaceShape84.wm" "polyUnite1.im[83]";
connectAttr "polySurfaceShape85.wm" "polyUnite1.im[84]";
connectAttr "polySurfaceShape86.wm" "polyUnite1.im[85]";
connectAttr "polyUnite1.out" "groupParts87.ig";
connectAttr "groupId89.id" "groupParts87.gi";
connectAttr "MeshShape.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "MeshShape.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape1.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape2.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape3.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape4.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape5.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape6.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape7.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape8.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape9.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape10.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape11.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape12.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape13.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape14.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape15.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape16.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape17.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape18.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape19.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape20.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape21.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape22.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape23.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape24.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape25.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape26.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape27.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape28.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape29.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape30.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape31.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape32.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape33.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape34.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape35.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape36.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape37.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape38.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape39.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape40.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape41.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape42.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape43.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape44.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape45.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape46.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape47.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape48.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape49.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape50.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape51.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape52.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape53.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape54.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape55.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape56.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape57.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape58.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape59.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape60.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape61.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape62.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape63.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape64.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape65.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape66.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape67.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape68.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape69.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape70.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape71.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape72.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape73.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape74.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape75.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape76.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape77.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape78.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape79.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape80.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape81.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape82.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape83.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape84.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape85.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape86.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape87.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "groupId1.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId2.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId3.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId4.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId5.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId6.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId7.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId8.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId9.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId10.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId11.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId12.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId13.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId14.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId15.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId16.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId17.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId18.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId19.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId20.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId21.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId22.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId23.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId24.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId25.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId26.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId27.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId28.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId29.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId30.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId31.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId32.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId33.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId34.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId35.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId36.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId37.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId38.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId39.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId40.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId41.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId42.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId43.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId44.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId45.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId46.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId47.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId48.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId49.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId50.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId51.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId52.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId53.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId54.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId55.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId56.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId57.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId58.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId59.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId60.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId61.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId62.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId63.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId64.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId65.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId66.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId67.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId68.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId69.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId70.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId71.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId72.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId73.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId74.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId75.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId76.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId77.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId78.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId79.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId80.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId81.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId82.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId83.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId84.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId85.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId86.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId87.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId88.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId89.msg" ":initialShadingGroup.gn" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
// End of shalidorsMaze.ma

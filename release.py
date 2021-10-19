#!/usr/bin/env python

import os,sys

specs = ['AliStandardLiveRoomBundle.podspec','AliInteractiveDocumentCore.podspec','AliInteractiveLiveCore.podspec','AliInteractiveRTCCore.podspec','AliInteractiveRoomBundle.podspec','AliInteractiveVideoPlayerCore.podspec','AliInteractiveWhiteBoardCore.podspec','AliStandardLiveRoomBundle.podspec']

if len(sys.argv) == 0:
    print('please input version')
else:
    version = sys.argv[1]

    for spec in specs:
    	with open(spec) as f:
            lines = f.readlines()
            for i in range(len(lines)):
                if lines[i].find('s.version      =') != -1:
                    lines[i] = "  s.version      = \"" + version + "\"" + "\n"
        f.close
        

        with open(spec,'w+') as wf:
            wf.writelines(lines)
            wf.close


    tag = "git tag -a "+version+" -m '"+version+"'"
    
    os.system('git add .')
    os.system('git commit -m release')
    os.system('git push')
    os.system(tag)
    os.system('git push --tags')


    lint = 'pod spec lint ' + spec + '--verbose'
    trunk = 'pod trunk push ' + spec

    for spec in specs:
        os.system(lint)
        os.system(trunk)
    

   
    

    
    
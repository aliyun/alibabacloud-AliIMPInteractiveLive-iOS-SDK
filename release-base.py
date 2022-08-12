#!/usr/bin/env python

import os,sys

specs = ['AliInteractiveRoomBundle.podspec','AliInteractiveDocumentCore.podspec','AliInteractiveLiveCore.podspec','AliInteractiveRTCCore.podspec','AliInteractiveVideoPlayerCore.podspec','AliInteractiveWhiteBoardCore.podspec','AliInteractiveFaceBeautyCore.podspec','AliInteractiveProduct360Core.podspec','AliStandardLiveRoomBundle.podspec','AliStandardClassroomBundle.podspec']

if len(sys.argv) == 0:
    print('please input version!!')
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

    for sp in specs:
        lint = 'arch -x86_64 pod spec lint ' + sp + ' --allow-warnings --quick'
        trunk = 'arch -x86_64 pod trunk push ' + sp + ' --allow-warnings'
        os.system(lint)
        os.system(trunk)
    

   
    

    
    

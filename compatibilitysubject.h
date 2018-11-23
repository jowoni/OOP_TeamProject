#ifndef COMPATIBILITYSUBJECT_H
#define COMPATIBILITYSUBJECT_H

#include <vector>
#include "allpartandgamedata.h"
#include "computerselection.h"
#include "compatibilityobserver.h"
#include "part.h"

class CompatibilitySubject
{
private:
    vector<CompatibilityObserver*> views;
public:
    void registerObserver(CompatibilityObserver *compObs);
//    {
//        views.push_back(compObs);
//    }
    void notifyAboutComboInitialize(int existCpu, string name);
//    { //observer에게 해당 부품 콤보박스 초기화 요청
//        for (vector<int>::size_type i = 0; i < views.size(); i++){
//            views[i]->update_compatibility_initialize(existCpu, name);
//        }
//    }
    void notifyAboutComboAdditem(Part *p, string name);
//    { //호환성 맞는 part를 추가하는 observer에게 part전달
//        for (vector<int>::size_type i = 0; i < views.size(); i++){
//            views[i]->update_compatibility(p, name);
//        }
//    }
    void observerCpuComboChanged(string cpuName);
//    {
//        list<PartData>::iterator pdIter;
//        list<Part*>::iterator ptIter;
//        string socketTemp;
//        for(pdIter = apag->getAllPartDataList()->begin(); pdIter != apag->getAllPartDataList()->end(); pdIter++){
//            if((pdIter->getPartName()).compare("cpu") == 0){
//                for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++) {
//                    if((*ptIter)->getName().compare(cpuName) == 0){
//                        socketTemp = dynamic_cast<CPU*>(*ptIter)->getSocket();
//                        cout << socketTemp << endl;
//                        break;
//                    }
//                }
//                break;
//            }
//        }
//        notifyAboutComboInitialize(1, "mainboard"); //메인보드 콤보박스 초기화
//        for(pdIter = apag->getAllPartDataList()->begin(); pdIter != apag->getAllPartDataList()->end(); pdIter++){
//            if((pdIter->getPartName()).compare("mainboard") == 0){
//                for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++) {
//                    if(dynamic_cast<Mainboard*>(*ptIter)->getSocket().compare(socketTemp) == 0){
//                        notifyAboutComboAdditem(*ptIter, "mainboard"); //호환성 맞는 part observer에게 전달
//                    }
//                }
//                break;
//            }
//        }
//    }

};

#endif // COMPATIBILITYSUBJECT_H

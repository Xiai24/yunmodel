import { createWebHashHistory, createRouter } from 'vue-router'

const routes = [
  { 
    path: '/', 
    name: 'Find',
    components: {
      main: () => import('../pages/GpuFind.vue'), 
      side: () => import('../components/MainSideSetting.vue')   
    }
  },
  
  { 
    path: '/detail', 
    name: 'detail',
    components: {
      main: () => import('../pages/GpuLook.vue'), 
      side: () => import('../components/MainSideSetting.vue')   
    }
  },
  
  {
    path: '/create',
    name: 'create',
    components: {  
      main: () => import('../pages/GpuContainer.vue'), 
      side: () => import('../components/SelectSideSetting.vue')   
    }
  }
]

const router = createRouter({
  history: createWebHashHistory(),
  routes
})

export default router
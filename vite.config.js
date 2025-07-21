import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'

// https://vite.dev/config/
export default defineConfig({
  plugins: [vue()],
   base: '/vuetest/'  // 必须以 / 开头和结尾，对应你的子路径
})
